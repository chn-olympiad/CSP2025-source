#include <bits/stdc++.h>
using namespace std;

const int MAXN=505;

int n,m;
string s;
int c[MAXN];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	
	int zeros=0;
	for (int i=1;i<=n;i++){
		cin>>c[i];
		zeros+=c[i]=='0';
	}
	
	int cnt=0;
	for (int i=0;i<n;i++){
		cnt+=s==1;
	}
	if (cnt==n){
		cout<<0;
	}
	
	return 0;
}
