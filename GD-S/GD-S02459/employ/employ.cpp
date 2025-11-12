#include<bits/stdc++.h>
using namespace std;
const int Mod = 998244352; 
int n,m;
int c[502];
int jc(int a){
	if(a==0) return 1;
	else return ((a%Mod) * ((a-1)%Mod))%Mod;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int t = n-m;
	int v = jc(t);
	int u = jc(n);
	cout<<u/v<<'\n';
}
