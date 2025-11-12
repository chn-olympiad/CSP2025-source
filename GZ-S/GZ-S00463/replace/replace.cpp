//GZ-S00463 六盘水市第四实验中学 陈子轩 
#include<bits/stdc++.h>
using namespace std;
int n,t,q;
string b[1000000][5],a[100000][5];
int main(){
	freopen("relace.in","r",stdin);
	freopen("relace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<q;i++){
		for(int j=0;j<2;j++){
			cin>>b[i][j];
		}
	}
	for(int i=0;i<q;i++){
		if(a[i]==b[i]) cout<<0;
		else if(b[i]==b[i+1]) cout<<1;
		else if(b[i][i].find(a[i][2])!=-1) cout<<1;
		else cout<<2;
	}
	return 0;
}
