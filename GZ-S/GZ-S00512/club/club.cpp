//GZ-S00512 贵阳市第三中学 龚子喻
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int t,n;
struct club{
	int a,b,c;
};
club c[N];
bool cmp (club ta,club tb){
	return ta.a > tb.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (int i = 1;i <= n;i++){
			scanf("%d%d%d",&c[i].a,&c[i].b,&c[i].c);
		}
		sort(c + 1,c + n + 1,cmp);
		int ans = 0;
		for (int i = 1;i <= n / 2;i++){
			ans += c[i].a;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
