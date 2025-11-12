#include <bits/stdc++.h>
using namespace std;
int n,q,m[200005][2];
unsigned long long h[200005][2];
vector<unsigned long long> u,v;
unsigned long long ha[500005];
unsigned long long bbh(int x,int l,int r){
	return (h[x][r]-h[x][l-1])/ha[l-1];
}
unsigned long long bbu(int l,int r){
	return (u[r]-u[l-1])/ha[l-1];
}
unsigned long long bbv(int l,int r){
	return (v[r]-v[l-1])/ha[l-1];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	ha[0]=1;
	for(int i=1;i<=200005;i++){
		ha[i]=ha[i-1]*131;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<2;j++){
			string s;
			cin>>s;
			m[i][j]=s.size();
			for(int x=1;x<=m[i][j];x++){
				h[i][j]=h[i][j]*131+s[x-1]-'a';
			}
		}
	}
	while(q--){
		int z=0;
		string a,b;
		int x=a.size(),y=a.size();
		cin>>a>>b;
		u.resize(1);
		v.resize(1);
		for(int i=1;i<=x;i++){
			u.push_back(u[i-1]*131+a[i-1]-'0');
		}
		for(int i=1;i<=y;i++){
			v.push_back(v[i-1]*131+b[i-1]-'0');
		}
		for(int i=1;i<=n;i++){
			for(int l=1;l+m[i][0]-1<=x;l++){
				if(bbu(l,l+m[i][0]-1)==h[i][0]&&u[x]-h[i][0]+h[i][1]==v[y])z++;
			}
		}
		cout<<z<<endl;
	}
}
