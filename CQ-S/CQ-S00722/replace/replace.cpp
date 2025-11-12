#include<bits/stdc++.h>
using namespace std;
int n,q,f[200005],l[200005];
string a[200005],b[200005],bza[200005],bzb[200005];
bool a1[200005],b1[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		int first=INT_MAX,last=0;
		for(int k=0;k<a[i].size();k++){
			if(a[i][k]!=b[i][k]){
				first=min(first,k);
				last=max(last,k);
			}
		}
		for(int k=first;k<=last;k++){
			bza[i]+=a[i][k];
			bzb[i]+=b[i][k];
		}
		f[i]=first+1;
		l[i]=last+1;
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		string x,y,bz1,bz2;
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<0<<'\n';
			continue;
		}
		int first=INT_MAX,last=0;
		for(int k=0;k<x.size();k++){
			if(x[k]!=y[k]){
				first=min(first,k);
				last=max(last,k);
			}
		}
		for(int k=first;k<=last;k++){
			bz1+=x[k];
			bz2+=y[k];
		}
		for(int j=1;j<=n;j++){
			if(bza[j]==bz1) a1[j]=1;
			if(bzb[j]==bz2) b1[j]=1;
			int flag=1;
			if(b1[j] && a1[j]){
				for(int ff=1;ff<f[j];ff++){
					if(a[j][f[j]-ff-1]!=x[first-ff]){
						flag=0;
						break;
					}
				}
				for(int ff=1;ff<=a[j].size()-l[j];ff++){
					if(a[j][l[j]+ff-1]!=x[last+ff]){
						flag=0;
						break;
					}
				}
				ans+=flag;
			}
			a1[j]=b1[j]=0;
			//cout<<ans<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}

