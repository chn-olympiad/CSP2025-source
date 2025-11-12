#include<bits/stdc++.h> 
#define int long long 
#define x first 
#define y second 
#define il inline 
#define eb emplace_back 
#define debug() puts("-----") 
using namespace std; 
typedef pair<int,int> pii; 
il int read(){ 
	int x=0,f=1; char ch=getchar(); 
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } 
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar(); 
	return x*f; 
} 
const int N=510; 
int n,m; 
string c; 
int a[N]; 
int p[N]; 
il void sol1(){ 
	int ans=0; 
	for(int i=1;i<=n;i++) p[i]=i; 
	do{ 
		int cnt=0,res=0; 
		for(int i=1;i<=n;i++){ 
			if(c[i]=='0'){
				cnt++; 
				continue; 
			} if(cnt>=a[p[i]]) cnt++; 
			else res++; 
		} if(res>=m) ans++; 
	}while(next_permutation(p+1,p+n+1)); 
	cout<<ans<<endl; 
} 
signed main(){ 
	freopen("employ.in","r",stdin); 
	freopen("employ.out","w",stdout); 
	n=read(),m=read(); cin>>c; c=" "+c; 
	for(int i=1;i<=n;i++) a[i]=read(); 
	if(n<=10){ 
		sol1(); 
		return 0; 
	} 
	return 0; 
} /*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3


*/
