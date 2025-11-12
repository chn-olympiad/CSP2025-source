#include<iostream>
#define ll long long 
using namespace std;
struct ey{
	char ss1[1001];
	char ss2[1001];
};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ll n,q;
	cin>>n>>q;
	ey s[n+1],t[q+1];
	ll ans[q]={};
	for(int i=0;i<n;i++){
		cin>>s[i].ss1 >>s[i].ss2 ;
	}
	for(int i=0;i<q;i++){
		cin>>t[i].ss1 >>t[i].ss2 ;
		cout <<"s:"<<i<<endl;
	}
	for(int i=0;i<n;i++){
		char x[1001],y[1001],z[1001],yz[1001];
		for(int j=0;j<n;j++){
			y[i]=s[i].ss1 [j]<<':'s[i].ss2 <<' ';
			
		}
		cout <<endl;
		if(s[i].ss1 ==t[i].ss1 )
		{
			ans[i]++;
			cout<<i<<'z'<<endl;
		}
		if(s[i].ss2==t[i].ss2 ){
			ans[i]++;
			cout<<i<<'d'<<endl;
			}
	}
	for(int i=0;i<q;i++ )
	cout<<ans[i]<<endl;
	
	return 0;
}
