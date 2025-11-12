#include <bits/stdc++.h>
using namespace std; 
const int N = 5e5 + 10;
int n, k, a[N], s[N], f[N];
bool ok = true;
bool b[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] != 1) ok = false;
		s[i] = s[i - 1] ^ a[i];
	}
	if (ok) {
		printf("%d\n", n / 2);
		return 0;
	}
	int sum = 0,ans=0;
	for (int i = 1; i <= n; i++)
		if(a[i]==k)ans++,b[i]=true;
	for(int i=1;i<=n;i++){
		if(b[i]){sum=0;continue;}
	//	printf("b:%d\n",b[i]);
		sum^=a[i];
	//	printf("sum:%d\n",sum); 
		if(sum==k)sum=0,ans++;
	}	
	printf("%d",ans);
	return 0;
} 
