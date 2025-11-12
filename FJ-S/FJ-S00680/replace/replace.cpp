#include<bits/stdc++.h>
using namespace std;
bool st(string sx,string sy){
	if(sx.size()!=sy.size())return false;
	for(int i = 0;i<sx.size();i++){
		if(sx[i]!=sy[i])return false;
	}
	return true;
}
int ss[5000010];
string ssx[200010];
string ssy[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		cin>>ssx[i]>>ssy[i];
		ss[i] = ssx[i].size();
	}
	for(int i = 1;i<=q;i++){
		int sum = 0;
		string tx,ty;
		cin>>tx>>ty;
		int m = tx.size();
		for(int k = 1;k<=n;k++){
			string tz = "";
			int j = 0;
			for(int i = 0;i<m;i++){
				if(ssx[k][j]!=tx[i]){
					tz+=tx[i];
				}else{
					tz+=ssy[k][j];
					j++;
				}
			}
			if(st(ty,tz))sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}

