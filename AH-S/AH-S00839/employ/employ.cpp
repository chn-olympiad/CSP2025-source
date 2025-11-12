#include<bits/stdc++.h>
using namespace std;
int a[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,sum=0;
    string s;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum!=n){
        cout<<0;
        return 0;
	}
	int ans=1;
	for(int i=0;s[i];i++){
		if(s[i]==1)ans*=n-i-1;
		else {
			if(i+1>=m)cout<<ans;
			else cout<<0;
			return 0;
		}
	}
    return 0;
}
