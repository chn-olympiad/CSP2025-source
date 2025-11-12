#include<bits/stdc++.h>
using namespace std;
int s[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		ans+=s[i];
		ans%=998244353;
	}
	if(n<3){
		cout<<0; 
	}
    if(n==3) {
    	if(s[1]+s[2]>s[3]&&s[2]+s[3]>s[1]&&s[3]+s[1]>s[2]){
    		cout<<1;
		}
	    else{
			cout<<0;
		}
	}
	if(n>3&&s[1]==1){
    	cout<<n-2;
	}
	if(n>3&&s[1]!=1){
    	cout<<ans;
	}
	return 0;
}
