#include<bits/stdc++.h>
#define int long long
using namespace std;
string a[200005],b[200005],c[200005],d[200005];
int off[200005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		off[i]=0;
		int l=1;
		for(int t=0;t<a[i].size();t++){
			if(a[i][t]!=b[i][t]){
				l=0;
				c[i]=c[i]+a[i][t];
				d[i]=d[i]+b[i][t];
			}
			else{
				off[i]+=l;
			}
		}
//		cout<<'-'<<c[i]<<' '<<d[i]<<' '<<off[i]<<'\n';
	}
//	cout<<"\n\n";
	for(int i=1;i<=q;i++){
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size()) {
			cout<<0<<'\n';
			continue;
		}
		int ans=0;
		string ch1,ch2;
		int off1=0;
		int fl=1;
		for(int t=0;t<x.size();t++){
			if(x[t]!=y[t]){
				fl=0;
				ch1=ch1+x[t];
				ch2=ch2+y[t];
			}else{
				off1+=fl;
//				cout<<a[i][t]<<' '<<b[i][t]<<'\n';
			}
		}
//		cout<<i<<':'<<ch1<<' '<<ch2<<'\n';
//		off1--;
		for(int j=1;j<=n;j++){
//			cout<<c[j]<<' '<<ch1<<' '<<d[j]<<' '<<ch2<<'\n';
			
			if(c[j]==ch1&&d[j]==ch2){
//				cout<<1;
//				if((a[j].size()>x.size())||(b[j].size()>y.size())){
//					continue;
//				}
//				cout<<a[j]<<'\n'<<x<<'\n'<<b[j]<<'\n'<<y<<'\n';
				if(off1-off[j]<0) continue;
				if(off1-off[j]+a[j].size()>x.size()) continue;
				if(x.substr(off1-off[j],a[j].size())==a[j]&&y.substr(off1-off[j],a[j].size())==b[j]){
					ans++;
				}
//				cout<<x.substr(off1-off[j],a[j].size())<<' '<<a[j]<<' '<<y.substr(off1-off[j],a[j].size())<<' '<<b[j]<<'\n';
//				cout<<off1<<'\n';
//				cout<<<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}