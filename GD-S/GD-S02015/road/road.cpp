#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010;
struct tt{
	int a,b,c;
}a[N];
int t,ans,n,f[N],m,k;
bool cmp1(tt a,tt b){//a>b>c;
	if(a.a==b.a){
		if(a.b==b.b)return a.c>b.c;
		else return a.b>b.b;
	}
	else return a.a>b.a;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	 
	return 0;
}

