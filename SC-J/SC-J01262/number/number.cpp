#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define ptc putchar
using namespace std;
const int N=1e6+5;
int n;
char c[N];
int cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c+1);
	n=strlen(c+1);
	for(int i=1;i<=n;i++){
		if('0'<=c[i]&&c[i]<='9'){
			++cnt[c[i]-'0'];
		}
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]){
			--cnt[i];
			printf("%d",i);
		}
	}
	ptc('\n');
	fclose(stdin);
	fclose(stdout);
	return 0;
}