#include<bits/stdc++.h>
using namespace std;
int n,k,a[1001],l[1001],r[1001],num1,num2;
long long sum=0,cnt=0;
bool vis[1001]={false},f=false;
bool solve(int p,int q){
	sum=a[q];
	for(int i=q+1;i<=p+q-1;i++){
		sum=sum^a[i];
	}
	if(sum==k){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			if(solve(i,j)){
				cnt++;
				l[cnt]=j;
				r[cnt]=j+i-1;
			cout<<l[cnt]<<" "<<r[cnt]<<endl;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		for(int j=l[i];j<=r[i];j++){
			if(vis[j]==true){
				cnt--;
				f=true;
				num1=l[i];
				num2=j-1;
				break;
			}
			vis[j]=true;
			cout<<j<<endl;
		}
		if(f){
			for(int k=num1;k<=num2;k++){
				vis[k]=false;
				cout<<" "<<k<<endl;
			}
			f=false;
		}
	}
	cout<<cnt;
	return 0;
}
