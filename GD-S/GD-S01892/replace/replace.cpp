#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define ll long long
const int N=2e5+5;
int n,q;
string s[N][3];
int ans;
int Find(string a,string b){
	for(int i=1;i<=a.size()-1;i++){
		bool ok=true;
		for(int j=1;j<=b.size()-1;j++){
			if(a[i+j-1]!=b[j]){
				ok=false;
				break;
			}
		}if(ok) return i;
	}return -1;
}
map<string,bool> vis;
void get(string t1,string t2,int step){
	if(step>2||vis.count(t1)) return;
	vis[t1]=1;
	if(t1==t2){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		while(true){
			int x=Find(t1,s[i][1]);
			if(x==-1) break;string bp=t1;
			for(int j=x;j<=x+s[i][1].size()-2;j++) t1[j]=s[i][2][j-x+1];
			if(t1!=bp)get(t1,t2,step+1);t1=bp; 
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		s[i][1]=" "+s[i][1],s[i][2]=" "+s[i][2];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		ans=0;
		get(t1,t2,0);
		cout<<ans<<'\n';
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
