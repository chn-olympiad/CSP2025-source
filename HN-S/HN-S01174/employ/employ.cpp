#include<bits/stdc++.h>
#define pii pair<int,int>
#define vti vector<int>
#define psbk push_back
#define fi first
#define se second

using namespace std;
const int N=200005,INF=0x3f3f3f3f,mod=998244353;
int n,m,an,b[N];
string s;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
    int a[11];
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) a[i]=i,cin>>b[i];
	do{
		int ct=0,k=0;
		for(int i=1;i<=n;i++){
			if(ct>=b[a[i]]) ct++;
			else{
				if(s[i-1]=='1') k++;
				else ct++;
			}
		}
		if(k>=m) an=(an+1)%mod;
	}while(next_permutation(a+1,a+1+n));
	cout<<an;
	return 0;
}/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
