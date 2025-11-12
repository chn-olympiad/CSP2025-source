#include<bits/stdc++.h>
using namespace std;
int n,k,a,qzh,qd=0,ans=0;
map<int,int>m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;m[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a;
		qzh=qzh^a;
		int yb=k^qzh;
		if(m[yb]>qd)ans++,qd=i;
		m[qzh]=i+1;
	}
	cout<<ans;
	return 0;
}
