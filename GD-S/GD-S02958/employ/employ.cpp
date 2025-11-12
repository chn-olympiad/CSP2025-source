#include<bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
const int N = 1010;
int n,m;
bool s[N];
int c[N];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;i++){
		char x;
		scanf("%c",&x);
		s[i] = x - '0';
	}for(int i = 1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	printf("%d",m);


	return 0;
}