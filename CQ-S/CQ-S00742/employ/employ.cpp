#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[510],p[510];
long long RP;
bool flag;
bool check(){
	int cnt1 = 0,cnt2 = 0;
	for(int i = 1;i <= n;i++){
		if(cnt2 >= c[p[i]]){
			cnt2++;
			continue;
		}
		if(s[i - 1] == '1'){
			cnt1++;
		}
		else{
			cnt2++;
		}
	}
	return cnt1 >= m;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin >> s;
	for(int i = 1;i <= n;i++){
		scanf("%d",&c[i]);
		p[i] = i;
	}
	do{
		if(check()){
			RP++;
			RP = RP % 998244353;
		}
	}while(next_permutation(p + 1,p + 1 + n));
	printf("%lld",RP);
	return 0;
}

