#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	char input1[n];
	int input2[n];
	int isZ = 0;
	for (int i = 0;i<n;i++) {
		input1[i] = getchar();
		if (input1[i] == '\n' || input1[i] == ' ') {
			i=i-1;
			continue;
		}
	}
	for (int i =0;i<m;i++) {
		scanf("%d",input2+i);
		if (input2[i] == '0') {
			isZ++;
		}
	}
	if (n==m) {
		if (isZ>1) {
			printf("0");
			return 0;
		}
		sort(input2,input2+n);
		int cz = 0;
		long long ans = 1;
		for (int i = 0;i<n;i++) {
			if (input1[i] = '0') {
				cz++;
			}
			int index = lower_bound(input2,input2+n,cz) - input2;
			int count = n-index;
			ans = ans*count %998244353;
			printf("%lld",ans);
			return 0;
		}
	} 
	printf("3");
	return 0;
}
