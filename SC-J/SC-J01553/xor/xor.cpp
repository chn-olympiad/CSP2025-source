#include<bits/stdc++.h>
using namespace std;
long long n,a[100000],sum,q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	int k=1<<n+1;
	for(int j=1;j<=k-1;j++){
		long long b=j,ans=0,cnt=0,flag=0;
		bool s=false;
		while(b!=0){
			cnt++;
			if(b&1==1){
				ans^=a[cnt];
				if(s==false){
					flag++;
				}
				s=true;
			}else{
				s=false;
			}
			b/=2;
		}
		if(ans==q){
			sum=max(sum,flag);
		}
	}
	cout<<sum;
	return 0;
}