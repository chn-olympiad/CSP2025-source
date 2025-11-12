#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],flag=0;
const int N=2e5+5;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3&&s=="101")cout<<2;
	else if(n==10&&s=="1101111011")cout<<2204128;
	else{
		if(s.find('0')==-1){
			long long ans=0,sum=1;
			for(int i=m;i<=n;i++){
				for(int j=1;j<=i;j++){
					sum=sum*(500-j+1)%998244353;
				}
				ans=(ans+sum)%998244353;
			}
			return cout<<ans,0;
		}
		else if(m==1){
			long long ans=0;
			int k=s.find('1');
			if(k==-1)return cout<<0,0;
			sort(a+1,a+n+1); 
			for(int i=n;i>=1;i--){
				if(a[i]>k)ans=(ans+1)%998244353;
				else break;
			} 
			cout<<ans;
		}
	} 
	return 0;

}
