#include<bits/stdc++.h>
using namespace std;
int n,q;
string y,yy;
int l,ll;
map<string,string> mp;
int a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>y>>yy;
		mp[y]=yy;
		a[i]=y.size();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=q;i++){
		cin>>y>>yy;
		l=y.size();
		ll=yy.size();
		if(ll!=l){
			cout<<0<<'\n';
			continue;
		}
		int cnt=0;
		for(int j=a[1];j<=a[n];j++){
			for(int k=0;k+j-1<=n;k++){
				string ss="";
				for(int l=0;l<j;l++){
					ss+=y[l+k];
				}
				string sss=y;
				if(mp[ss]!=""){
					for(int l=0;l<j;l++){
						sss[l+k]=mp[ss][l];
					}
					//cout<<sss<<'\n';
					if(sss==yy){
						cnt++;
					}
				}
				
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
