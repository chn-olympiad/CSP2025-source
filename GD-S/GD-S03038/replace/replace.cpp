#include<bits/stdc++.h>
#define N 200010
#define M 5000010
using namespace std;
int n,q;
string sx[N],sy[N];
map<int,int> mp;
int fd(string x){
	int sz=x.size();
	for(int i=0;i<sz;i++){
		if(x[i]=='b') return i;
	}
	return -1;
}
int main(){
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1,xf,yf;i<=n;i++){
		cin>>sx[i]>>sy[i];
		xf=fd(sx[i]),yf=fd(sy[i]);
		if(mp.find(xf-yf)!=mp.end()) mp[xf-yf]++;
		else mp[xf-yf]=1;
	}
	for(int j=1,tx,ty,xf,yf;j<=q;j++){
		string ns="";
		cin>>tx>>ty;
		xf=fd(tx),yf=fd(ty);
		if(mp.find(xf-yf)==mp.end()) cout<<0;
		else cout<<mp[xf-yf];
	}
	return 0;
}

