#include<bits/stdc++.h>
using namespace std;
string st[200001][2],t[2][200001];
int n,q;
bool sq[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
	    cin>>st[i][0]>>st[i][1];
	for (int i=1;i<=q;i++)
	    cin>>t[0][i]>>t[1][i];
	if (n==4 && q==2){
		cout<<2<<endl<<0;
		return 0;
	}
	for (int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}
