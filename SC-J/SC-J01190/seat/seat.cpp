#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100000;
long long data1[MAXN],n,m,temp,pos,cnt;
bool compare(const long long &x,const long long &y);
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for (long long i = 1;i <= n * m;i ++){
		scanf("%lld",&data1[i]);
	}
	temp = data1[1];
	sort(data1 + 1,data1 + 1 + n * m,compare);
	for (long long i = 1;i <= n * m;i ++){
		if (data1[i] == temp){
			pos = i;
		}
	}
	for (long long i = 1;i <= m;i ++){
		if (i & 1){
			for (long long j = 1;j <= n;j ++){
				cnt ++;
				if (cnt == pos){
					printf("%lld %lld\n",i,j);
					return 0;
				}
			}
		} else {
			for (long long j = n;j >= 1;j --){
				cnt ++;
				if (cnt == pos){
					printf("%lld %lld\n",i,j);
					return 0;
				}
			}
		}
	}
	return 0;
}
bool compare(const long long &x,const long long &y){
	return x > y;
}