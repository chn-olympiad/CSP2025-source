#include <bits/stdc++.h>
using namespace std;
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define pint pair<int,int>
#define fst first
#define snd second
#define int long long

const int N = 1e6 + 5;
char s[N];

vector <int> ss;
bool cmp(int a,int b){
	return a > b;
}
signed main(){
	FRR("number.in");
	FRW("number.out");
	scanf("%s",s+1);
	int n = strlen(s+1);
	for(int i=1;i<=n;++i){
		if(s[i] >= '0' && s[i] <= '9'){
			ss.push_back(s[i]-'0');
		}
	}
	sort(ss.begin(),ss.end(),cmp);
	for(int i:ss) cout << i;
	return 0;
}
