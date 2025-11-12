#include <iostream>
#include <cstdio>
using namespace std;
int n,t,na,nb,nc,ans;
struct student{
	int a;
	int b;
	int c;
	int maxn;
}s[200005];
long long dfs(int x){
	if(x > n)return 0;
	int ta=0,tb=0,tc=0;
	na++;
	if(na <= (n/2))ta = s[x].a+dfs(x+1);
	na--;
	nb++;
	if(nb <= (n/2))tb = s[x].b+dfs(x+1);
	nb--;
	nc++;
	if(nc <= (n/2))tc = s[x].c+dfs(x+1);
	nc--;
	return max(ta,max(tb,tc));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int j = 1;j <= t;j++){
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> s[i].a >> s[i].b >> s[i].c;
			s[i].maxn = max(s[i].a,max(s[i].b,s[i].c));
		}
		cout << dfs(1) << endl;
	}
		
	return 0;
}
