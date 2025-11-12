#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	string s1,s2;
}a[200050];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	while(m--){
		string x,y;
		int ans=0;
		cin>>x>>y;
		int lx=x.size();
		int ly=y.size();
		x=" "+x;
		y=" "+y;
		for(int i=1;i<=n;i++){
			int p=x.find(a[i].s1);
			if(p!=-1){
				string u=x;
				u.erase(p,(int)a[i].s1.size());
				u.insert(p,a[i].s2);
				if(u==y) ans++;
			}
		
		}
		cout<<ans<<'\n';
	}
	return 0;
}


