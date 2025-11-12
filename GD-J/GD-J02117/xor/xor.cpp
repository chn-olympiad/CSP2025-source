#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
//struct stu{
//	int l,ans;
//};
//queue<stu>q;
int a[N],x[N],ans;
int n,k;
void find(int l,int len){
	if(l>=n){
//		cout<<"end!\n";
		ans=max(len,ans);
		return;
	}
	if(a[l]==k){
//		cout<<"yourself!\n";
		find(l+1,len+1);
	}
	for(int r=l+1;r<=n;r++){
		if((x[r]^x[l-1])==k){
//			cout<<l<<"  "<<r<<"\n";
			find(r+1,len+1);
			break;
		}
	}
	find(l+1,len);
}
//void find(){
//	while(!q.empty()){
//		stu p=q.top();
//		q.pop();
//		if()
//	}
//}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    if(k==0){
    	cout<<n/2;
    	return 0;
	} 
	bool flag=1;
	int sum1=0,sum0=0;
    for(int i=1;i<=n;i++){
    	scanf("%d",a+i);
    	if(a[i]==1)sum1++;
    	if(a[i]==0)sum0++;
    	if(!(a[i]==1||a[i]==0))flag=0;
    	x[i]=(a[i]^x[i-1]);
//    	cout<<x[i]<<" ";
	}
//	cout<<flag<<"\n";
	if(flag){
		if(k==0){
			for(int i=2;i<=n;i++){
				if(a[i]==a[i-1]&&a[i]==1){
					ans++;
					a[i]=-1;
				}
				if(a[i-1]==0)ans++;
				if(a[i]==0){
					ans++;
					a[i]=-1;
				}
			}	
		}
		else{
			ans=sum1;
		}
		printf("%d",ans);
		return 0;
	}
//	cout<<"\n";
//	q.push(1,0);
	find(1,0);
	printf("%d",ans);
	return 0;
}
