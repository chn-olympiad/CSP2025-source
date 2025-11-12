#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int N=100010;
const int MOD=998244353;
int n,m;
ll fac(int x){
	ll res=1;
	for(int i=2;i<=x;i++) res=(ll)res*i%MOD;
	return res;
}

struct inv
{
	int l,r,len;
}g[510];
int cnt=0;
void addinv(int l,int r,int len){
	cnt++;
	g[cnt].l=l;
	g[cnt].r=r;
	g[cnt].len=len;
}
int c[510];
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	cin>>n>>m;
	char ch[1000];
	cin>>ch;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) cout<<fac(i)<<'\n';
	return 0;
}