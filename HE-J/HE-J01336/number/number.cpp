#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
char s;
int a[N],cnt;
int u = 1;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(s = getchar()){
		if(s == '\n') break;
		if(s >= '0' && s <= '9'){
			a[u] = s - '0';
			u++;
			cnt++;
		}
	}
	sort(a + 1,a + cnt + 1,cmp);
	for(int i = 1; i <= cnt; i++) printf("%d",a[i]);
	return 0;
}
