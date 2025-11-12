#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string q;
int c[1000005];
int jc(int x){
	int s=1;
	for(int i=1;i<=x;i++){
		s*=i;
		s%=998244353;
	}
	return s;
}
/*void slove(int N){
	if()
	for(i)
}*/
signed main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin>>n>>m>>q;
	int s=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(q[i-1]=='1'){
			s++;
		}
	}
	if(s<m)
	{
		cout<<0;
		return 0;
	}
	if(s==n){
		cout<<jc(n);
		return 0;
	}
	//slove(1);
    return 0;
}
