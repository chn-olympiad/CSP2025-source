#include<bits/stdc++.h>
using namespace std;
long long n,k,a[600010],s[600010],ans;
bool chose[600010];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			bool falg=true;
			int l=s[j]^s[i-1];
			if(l==k) {
				if(chose[i]||chose[j]) {
					falg=false;
				}
				if(falg) {
					ans++;
					for(int y=i; y<=j; y++)chose[y]=true;
					cout<<i<<" "<<j<<" "<<l<<endl;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
