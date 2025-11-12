#include<bits/stdc++.h>
using namespace std;
int ans,n,k,a[500005],s[500005],l;
bool flag=true,flag1=true; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1){
			flag=false;
		}
		if(a[i]>1){
			flag1=false;
		}
		if(i!=1){
			s[i]=s[i-1]^a[i];
		}else{
			s[i]=a[i];
		}
	}
	if(flag){
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int p=s[i]^s[l];
//		cout<<p<< endl;
		if(p==k){
//			printf("%d",s[i]^s[l]);
			ans++;
//			cout<<s[i]<<' '<<s[l]<<' '<<l<<' '<< endl;
			l=i;
		}
	}
	cout<<ans;
	return 0; 
}
