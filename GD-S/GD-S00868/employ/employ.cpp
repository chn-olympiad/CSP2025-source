#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string s;
    cin>>n>>m;
    cin>>s;
    int a[1000];
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			cnt++;
		}
	}
	long long ans=1;
	for(int i=2;i<=n-cnt+1;i++){
		ans=ans*i%998244353;
	}
	cout<<ans;
	return 0; 
}
