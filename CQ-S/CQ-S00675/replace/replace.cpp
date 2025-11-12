#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[100005],b[100005],x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	while(q--){
		cin>>x>>y;
		int siz=x.size();
		int cnt=0,cd=0,f=0,L=0,R=0;
		for(int i=0;i<siz;i++){
			if(x[i]!=y[i]){
				if(f==0) cd++,L=i;
				cnt++,f=1;
			} 
			else{
				if(f==1) cd++,R=i-1;
				f=0;
			}
		}
		if(R==0) R=siz-1;
		if(cd>2){cout<<0;continue;}
		int ans=0;
		for(int i=1;i<=n;i++){
			int l=a[i].size();
			for(int j=0;j+l-1<siz;j++){
				string tx=x.substr(j,l),ty=y.substr(j,l);
				if(tx==a[i] && ty==b[i]){
					if(j<=L && j+l-1>=R) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
