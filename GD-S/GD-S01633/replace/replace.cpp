#include<bits/stdc++.h>
#define uint unsigned int
using namespace std;

const int N=2e5+5;

int n,q;
struct mm{
	string a,b;
	int l;
	friend bool operator < (mm x,mm y){
		return x.l<y.l;
	}
} s[N];
string u,v;

signed main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
		s[i].l=s[i].a.size();
	}
	sort(s+1,s+n+1);
	
	while(q--){
		
		cin>>u>>v;
		int cnt=0;
		int maxh=-1,maxe=u.size();
		while(u[maxh+1]==v[maxh+1]) maxh++;
		while(u[maxe-1]==v[maxe-1]) maxe--;
		for(int i=0;i<=maxh+1;i++){
			for(int j=1;j<=n;j++){
				if(s[j].l<maxe-i) continue;
				int l=s[j].l;
				if(u.substr(i,l)==s[j].a && v.substr(i,l)==s[j].b) cnt++;
			}
		}
		
		cout<<cnt<<"\n";
		
	}
	
	return 0;
	
} 
