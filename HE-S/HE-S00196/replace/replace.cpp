#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,q;
string a[200001];
int t[5000010][27];
int f=0;
map<int,int> m;
struct aaa{
	int i;
	string j,k;
}c[200010];

int re(char x){
	return x-'a'+1;
}
bool se(int i,string o,int l){
	for(int j=0;j<=a[i].size()-1;j++){
		if(o[l-c[i].i+j]!=a[i][j]) return 0;
	}
	return 1;
}
void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string b;
		cin>>a[i]>>b;
		for(ll j=0;j<a[i].size();j++){
			if(a[i][j]!=b[j]){
				c[i].i=j;
				int l;
				for(ll x=a[i].size()-1;x>=0;x--){
					if(a[i][x]!=b[x]){
						l=x;
						break;
					}
				}
				for(ll x=c[i].i;x<=l;x++){
					c[i].j+=a[i][x];
					c[i].k+=b[x];
				}
				break;
			}
		}
	}
	for(int i=1;i<=q;i++){
		string o,p;
		int s=0;
		cin>>o>>p;
		string w,e;
		int l,r;
		for(ll j=0;j<o.size();j++){
			if(o[j]!=p[j]){
				l=j;
				for(ll x=o.size()-1;x>=0;x--){
					if(o[x]!=p[x]){
						r=x;
						break;
					}
				}
				for(ll x=l;x<=r;x++){
					e+=o[x];
					w+=p[x];
				}
				break;
			}
		}
		for(ll j=1;j<=n;j++){
			if(e==c[j].j&&w==c[j].k){
				s+=se(j,o,l);
			}
		}
		cout<<s<<endl;
	}
	return;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	solve();
	
	return 0;
}
