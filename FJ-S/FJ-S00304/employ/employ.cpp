#include<bits/stdc++.h>
using namespace std;
int n,m,c[10000],cc=0,f=1,mm=0;
string s;
int ans=0;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1; i<=n; i++){
		cin>>c[i];
		f*=i;
	}
	for(int j=1; j<=f; j++) {
		cc=0;mm=0;
		for(int i=1; i<=n; i++) {
//			cout<<s[i-1]<<" "<<c[i]-cc<<endl;
			
			if(s[i-1]==1&&c[i]-cc>=0) {
				mm++;
			} else {
				cc++;
			}
		}
		cout<<endl;
		if(mm>=m) ans++; 
	}
	cout<<1;
	return 0;
}
