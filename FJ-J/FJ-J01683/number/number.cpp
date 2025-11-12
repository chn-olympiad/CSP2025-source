#include <cstdio>
#include <cstring>
using namespace std;

char s[1000005];
int cnt[260];

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	scanf("%s", s);
	
	for(int i=0;i<strlen(s);i++){
		cnt[s[i]]++;
	}
	
	for(int i=(int)(9+'0');i>=(int)(0+'0');i--){
		for(int j=1;j<=cnt[i];j++){
			printf("%d", (int)(i-'0'));
		}
	}
	
	return 0;
}

/*
???为什么一个O(n)的算法会在n=10^6时超时啊????
细节测试number4.in时"64.3s"
i cant understand it;
*/
