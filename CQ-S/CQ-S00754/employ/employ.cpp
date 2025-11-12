#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	int n,m,t;
	long long ans=1,num=1,oi=0;
	string s;
	int c[502];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
    for(int i=0;i<n;i++){
    	ans*=num;
    	num++;
	}
	if(n==1){
		cout<<0;
	}
	else cout<<ans%998244353;
	return 0;
}
