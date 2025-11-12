#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=510,Mod=998244353;
int n,m;
string s;
struct Node{
	int c;
	int id;
}c[N];

LL timess(int k){
	if(k==0||k==1)return 1;
	return ((k%Mod)*(timess(k-1)%Mod))%Mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i].c;
		c[i].id=i;
	}
	LL ans=timess(n);
	cout<<ans;
	return 0;
}
