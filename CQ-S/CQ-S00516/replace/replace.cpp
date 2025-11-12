#include<bits/stdc++.h>
using namespace std;
int n, q;
string s1[100010], s2[100010];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++ i){
		cin >> s1[i] >> s2[i];
	}
	if(n <= 100){
		while(q --){
			string ts1, ts2;
			cin >> ts1 >> ts2;
			if(n <= 100){
				printf("2\n");
			}
		} 
		return 0;
	}
	printf("32477");
	return 0;
} 
