#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5,S = 5e6 + 5;
int n,q;
string arr[N],brr[N];
char s1[S],s2[N];
inline ll read(){
	ll x = 0;char c = getchar();
	while(c < '0' || c > '9'){
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x<<1) + (x<<3) + (c^48);
		c = getchar();
	}
	return x;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n = read();q = read();
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 1; i <= n; ++i){
		cin >> arr[i] >> brr[i];
	}
	string a,b;
	for(int i = 1; i <= q; ++i){
		cin >> s1 >> s2;
		if(strlen(s1) != strlen(s2)){
			printf("0\n");
		}
		else{
			ll cnt = 0;
			for(int j = 1; j <= n; ++j){
//				printf("(%d) ",j);
				for(int k = 0; k < int(strlen(s1) - arr[j].size() + 1); ++k){
//					printf("k : %d\n",k);
					int t = k;
					bool f = true;
					for(int p = 0; p < arr[j].size(); ++p){
						if(s1[t] != arr[j][p]){
							f = false;
							break;
						}
						else{
//							printf("t(%d) ",t);
							++t;
						}
					}
//					printf("\n");
					if(f){
						
						f = true;
						for(int p = 0; p < k; ++p){
							if(s1[p] != s2[p]){
								f = false;
								break;
							}
						}
						if(!f){
							continue;
						}
						for(int p = 0; p < arr[j].size(); ++p){
							if(arr[j][p] != s2[k + p]){
								f = false;
								break;
							}
						}
						if(!f){
							continue;
						}
						for(int p = k + arr[j].size(); p < strlen(s1); ++p){
							if(s1[p] != s2[p]){
								f = false;
								break;
							}
						}
						if(f){
							++cnt;
						}
					}
				}
			}
			printf("%lld\n",cnt);
		}
	}
	return 0;
} 
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
