#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second 
using namespace std;
const int N=505;
int n,m;
string s;
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;++i) cin>>c[i];
	if(n<=10){
		int id[20]; 
		for(int i=1;i<=n;++i){
			id[i]=i;
		}
		int ans=0;
		do{
			int cnt=0;
			for(int i=1;i<=n;++i){
				if(cnt>=c[id[i]]) ++cnt;
				else {
					if(s[i]=='0') ++cnt;
				}
			}
			if(n-cnt>=m){
				++ans;
			}
		} while(next_permutation(id+1,id+n+1));
		cout<<ans<<endl;
	}
	
	return 0;
}
