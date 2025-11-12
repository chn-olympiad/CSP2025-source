#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=2e5+10;
int n,q,m,ans;
string fr[N],to[N]; 
vector<int>vp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>fr[i]>>to[i];
	while(q--){
		string a,b;
		cin>>a>>b;
		m=a.size();
		a=" "+a;
		b=" "+b;
		vp.clear();
		int l=m+1,r=0;
		for(int i=1;i<=m;i++){
			if(a[i]!=b[i])
				vp.push_back(i),
				l=min(l,i),
				r=max(r,i);
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if((int)fr[i].size()<(r-l+1)) continue;
			int pos=1,len=fr[i].size();
			//cout<<"find "<<a<<" "<<fr[i]<<"\n";
			vp.clear();
			while(a.find(fr[i],pos)!=a.npos){
				int fp=a.find(fr[i],pos);
				vp.push_back(fp);
				pos=fp+1;
			}
			if(!vp.size()) continue;
			for(auto st:vp){
				bool fl=1;
				for(int j=1;j<=m;j++){
					char na=(j>=st&&j<=st+len-1)?to[i][j-st]:b[j];
					if(na!=b[j]) fl=0;	
				}
				ans+=fl;
			}
			//cout<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
