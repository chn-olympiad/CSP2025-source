#include <bits/stdc++.h>
using namespace std;
int n,q;
string a[200001][2],b[2];
int diff[200001][2];
void pr(){
	for(int i=1;i<=n;i++){
		int len=a[i][0].size();
		for(int j=0;j<len;j++){
			if(a[i][0][j]!=a[i][1][j]){
				diff[i][0]=j;
				break;
			}
		}
		for(int j=len;j>=0;j--){
			if(a[i][0][j]!=a[i][1][j]){
				diff[i][1]=j;
				break;
			}
		}
	}
}
void solve(){
	int d0,d1,ans=0;
	int len=b[0].size();
	for(int j=0;j<len;j++){
		if(b[0][j]!=b[1][j]){
			d0=j;
			break;
		}
	}
	for(int j=len;j>=0;j--){
		if(b[0][j]!=b[1][j]){
			d1=j;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(diff[i][1]-diff[i][0]!=d1-d0){
			continue;
		}
		int s=d0-diff[i][0];
		int t=s+a[i][0].size()-1;
		if(s<0||t>=len){
			continue;
		}
		int f=1;
		for(int x=0,y=s;x<a[i][0].size(),y<=t;x++,y++){
			if(a[i][0][x]!=b[0][y]||a[i][1][x]!=b[1][y]){
				f=0;
				break;
			}
		}
		ans+=f;
	}
	printf("%d\n",&ans);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	pr();
	for(int i=1;i<=q;i++){
		cin>>b[0]>>b[1];
		solve();
	}
	return 0;
}

