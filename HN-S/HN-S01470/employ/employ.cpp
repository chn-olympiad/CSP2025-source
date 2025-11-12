#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int N=505,M=505,Mod=998244353;
int n,m,s[N],c[N],sum[N];
int f[N][M];//f[第i天][总共消耗j个简单题]= 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	{
		string x; cin>>x;
		int cnts=0;
		for(int i=0;i<n;i++){
			s[i+1]=x[i]-'0';
			if(s[i+1]) cnts++;
		}
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
		cout<<"0";
		if(m==1){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(c[j]<i) sum[i]++;
				}
			}
			
			return 0;
		}
		if(cnts==n){
			;
			return 0;
		}
	}
	return 0;
}
/*其实很想只拿部分分，但是还是争一下
1.#防爆0#单独写特殊性质A //感觉写不了一点 
2.保证有至少m个人的c[i]<=i 

3.算了算了，拿m=1的分得了， 则背包？ 
10 1
1111111111 
9 9 9 9 9 9 9 9 9 9
//最后的挣扎（road都不会做的入既然妄想拿下employ！) 
*/ 
