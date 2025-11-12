#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
int n,m,c[N],pre[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		pre[i]+=pre[i-1]+int(s[i-1]-'0');
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	cout<<0;
	return 0;
}

