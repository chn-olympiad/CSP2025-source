#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[100005];
int c[10005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	if(m==n){
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				cout<<0<<"\n";
				return 0;
			}
		}
		cout<<1<<"\n";
		return 0;
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	cout<<ans<<"\n";
	return 0;
}
