#include<bits/stdc++.h>
using namespace std;
int n,m,i=0,a[520],b[520],c=0,k=0;
long long int ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int j=1;j<=n;j++){
		cin>>a[j];
	}
	while(s[i]){
		
		if(s[i]=='1'){
			k++;
            b[i]==1;
		}
		i++;
	}
	
	if(k==n||m==n){
		for(int j=1;j<=n;j++){
			ans=ans*j;
		}
		cout<<ans%998244353<<endl;
	}else{
		 if(m==1){
		 	if(b[0]==1){
		 		for(int j=1;j<=n;j++){
					ans=ans*j;
				}
				cout<<ans%998244353<<endl;
			}else{
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
