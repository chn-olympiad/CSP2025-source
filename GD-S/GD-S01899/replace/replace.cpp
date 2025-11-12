#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int B=41;
int n,q,l[200010];
string s1[200010],s2[200010];
unsigned long long hh1[200010],hh2[200010];
unsigned long long ha[5000010],hb[5000010],d[5000010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	d[0]=1;
	for(int i=1;i<=5000000;i++){
		d[i]=d[i-1]*B;
	}
	cin>>n>>q;
	if(n<=1e3&&q<=1e3&&q!=1){
		int mx=0;
		for(int i=1;i<=n;i++){
			cin>>s1[i]>>s2[i];
			l[i]=s1[i].size();
			mx=max(mx,l[i]);
			s1[i]=" "+s1[i];
			s2[i]=" "+s2[i];
			for(int j=1;j<=l[i];j++){
				hh1[i]=hh1[i]*B+s1[i][j]-'a';
				hh2[i]=hh2[i]*B+s2[i][j]-'a';
			}
		}
		while(q--){
			string a,b;
			cin>>a>>b;
			int m=a.size();
			a=" "+a;
			b=" "+b;
			for(int i=1;i<=m;i++){
				ha[i]=ha[i-1]*B+a[i]-'a';
				hb[i]=hb[i-1]*B+b[i]-'a';
			}
			int l2=1,r=m;
			while(l2<r&&a[l2]==b[l2])l2++;
			while(l2<r&&a[r]==b[r])r--;
			ll ans=0;
			for(int i=1;i<=n;i++){
//				cout<<s1[i]<<" "<<s2[i]<<'\n';
				for(int x=1;x+l[i]-1<=m;x++){
					int y=x+l[i]-1;
//					cout<<ha[x-1]<<" "<<hb[x-1]<<'\n';
					if(ha[x-1]==hb[x-1]&&ha[y]-ha[x-1]*d[y-x+1]==hh1[i]&&hb[y]-hb[x-1]*d[y-x+1]==hh2[i]&&ha[m]-ha[y]*d[m-y]==hb[m]-hb[y]*d[m-y]){
						ans++;
	//					cout<<i<<" "<<x<<" "<<y<<'\n';
					}
				}
			} 
			cout<<ans<<'\n';
		}
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>s1[i]>>s2[i];
			l[i]=s1[i].size();
			s1[i]=" "+s1[i];
			s2[i]=" "+s2[i];
			for(int j=1;j<=l[i];j++){
				if(s1[i][j]=='b')hh1[i]=j;
				if(s2[i][j]=='b')hh2[i]=j;
			}
		}
		while(q--){
			string a,b;
			cin>>a>>b;
			int m=a.size();
			a=" "+a;
			b=" "+b;
			int x,y;
			for(int i=1;i<=m;i++){
				if(a[i]=='b')x=i;
				if(b[i]=='b')y=i;
			}
			ll ans=0;
			for(int i=1;i<=n;i++){
				if(y-x==hh2[i]-hh1[i]&&x>=hh1[i]&&m-y+1>=l[i]-hh2[i]+1)ans++;
			}
			cout<<ans<<'\n';
		}
		
	}
	return 0;
}
/*
fc D:\GD-S01899\replace\replace4.ans D:\GD-S01899\replace\replace.out
*/
