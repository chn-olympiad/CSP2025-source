#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,q,ans;
string a[N],b[N];
string st,en;
void work(string k){
	for(int i=1;i<=n;i++){
		int p=k.find(a[i]);
		while(p!=-1){
			for(int j=p;j<p+a[i].size();j++){
				k[j]=b[i][j-p];
			}
			if(k==en)
				ans++;
			for(int j=p;j<p+a[i].size();j++){
				k[j]=a[i][j-p];
			}
			p=k.find(a[i],p+a[i].size());
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int i=1;i<=q;i++){
		cin>>st>>en;
		work(st);
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
