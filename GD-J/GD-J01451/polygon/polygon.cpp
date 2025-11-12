#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
const int N=3e6+10,inf=0x3f3f3f3f,mod=998244353;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef long long ll;
/*
10:25
bitset?

10:28
Super ultra great delicious wonderful task.
Change:
p \in [1,2^t].
2l_t<\sum_{l_i<l_t}[(p>>i)&1]l_i

10:41
let m = \max a_i
O(n^3m) dp:
  f[i][m][V] (choose m items in i's,V is the sum of them.)
= f[i-1][m][V] + f[i-1][m-1][V-a[i]]

10:50
I have to write the partial score first.
Case 1(50 pts,idx=1-10):
	using O(n^3m) dp.
Case 2(24 pts,idx=15-20):
	the answer is 2^n-C(n,3) (easy to calculate). 

10:55
Wait!
DP is actrually(How to spell this word?) O(n^2m)
f[i][m][V] -> f[i][V] 
Scroll arr: f[i][V]->f[V]

11:14
Task4 done.
WA on polygon3

11:16
It just output a random number?!
Oh I forget to let V>=a[i].
WA again.

11:23
I need a duipai code.

11:34
I have to change Case 1 to O(2^n) algorithm.

11:43 
I find a mistake in my dpCase.
We update the answer if and only if V if bigger than 2*a[i].
I fixed it, and it passed polygon4.

I made a dpEX Case, I guess V just need to bigger than 2*a[i].
I can't proof it.
*/
int n,m,a[N],ans,sum;
int quickMi(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=(res*a)%mod;
		a=(a*a)%mod,b>>=1;
	}
	return res;
} 
void mian2(){
	ans=(quickMi(2,n)-n*(n-1)%mod*(n-2)%mod*quickMi(6,mod-2)%mod)%mod+mod;
	cout<<ans%mod;
}
int f[N],cnt;
void mian1(){
	for(int i=1;i<(1ll<<n);i++){
		int sum=0,cnt=0,mx=0;
		for(int j=0;j<n;j++)
			if((i>>j)&1) sum+=a[j+1],++cnt,mx=max(a[j+1],mx); 
		if(cnt>2&&sum>2*mx) ++ans;
	}
	cout<<ans;
}
void miandp(){
	for(int i=1;i<=n;i++){
		sum+=a[i];
		for(int V=sum;V>=a[i];--V){
			f[V]=(f[V]+f[V-a[i]]+(V==a[i]))%mod;
			if(V>2*a[i]) cnt=(cnt+f[V-a[i]])%mod;
		}
	}
	cout<<cnt;		
}
void miandpEX(){
	for(int i=1;i<=n;i++){
		sum+=a[i];
		for(int V=sum;V>2*a[i];--V){
			f[V]=(f[V]+f[V-a[i]]+(V==a[i]))%mod;
			if(V>2*a[i]) cnt=(cnt+f[V-a[i]])%mod;
		}
	}
	cout<<cnt;		
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1); m=a[n];
	if(m==1) mian2();
	else if(n<=20) mian1();
	else if(n<=500)miandp();
	else miandpEX();
	return 0;
}

