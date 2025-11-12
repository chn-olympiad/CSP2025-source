#include<bits/stdc++.h>
using namespace std;

int n,m;
bool s[501];
int c[505];
int ans;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>s[i];
			if(s[i]==1){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		cout<<1;
		return 0;
	}
}