#include<bits/stdc++.h>
using namespace std;
int n,q,ss,e;
long long ans;
string x,y;
struct node{
	string o,t;
}s[200010];
bool f[5000010],ff;
void hbAxz(int a,int b){
	char r[5000010],w[5000010];
	int rk=0,wk=0;
	for(int i=a;i<=b;i++){
		r[rk++]=x[i];
		w[wk++]=y[i];
	}
	for(int i=1;i<=n;i++){
		ff=1;
		if(s[i].o.size()==rk){
			for(int j=0;j<rk;j++){
				if(s[i].o[j]!=r[j]){
					ff=0;
					break;
				}
			}
		}
		if(!ff) continue;
		for(int j=0;j<wk;j++){
			if(s[i].t[j]!=w[j]){
				ff=0;
				break;
			}
		}
		if(!ff) continue;
		ans++;
	}
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i].o>>s[i].t;
	while(q--){
		cin>>x>>y;
		memset(f,1,sizeof(f));
		ss=e=0;
		ans=0;
		if(x.size()!=y.size()){
			cout<<0;
			continue;
		}
		for(int i=1;i<=n;i++) if(x[i]!=y[i]) f[i]=0;
		for(int i=1;i<=n;i++){
			if(!f[i]&&!ss){
				ss=i;
				break;
			}
		}
		for(int i=n;i>=1;i--){
			if(!f[i]&&!e){
				e=i;
				break;
			}
		}
		for(int i=1;i<=ss;i++) for(int j=e;j<=n;j++) hbAxz(i,j);
		cout<<ans<<"\n";
	}
	return 0;
}

