#include<cstdio>
#include<cstring>

const int MAXN = 1e6+5;
char c[MAXN] = {};
int h[10] = {};

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", c);
	int n = strlen(c);
	int flag = 0;
	for(int i = 0; i<=n-1; i++){
		if(c[i] >= '0' && c[i] <= '9'){
			h[c[i]-'0']++;
			if(c[i] != '0') flag = 1;
		}
	}
	
	if(flag == 0){
		printf("0");
		return 0;
	}
	for(int i = 9; i>=0; i--){
		for(int j = 1; j<=h[i]; j++){
			printf("%d", i);
		}
	}
	return 0;
}

