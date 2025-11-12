#include<bits/stdc++.h>
using namespace std;
char a[1200000];
int n,b[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s" ,a);
	n = strlen(a);
	for(int i = 0;i < n;i++){
		if(a[i] >= '0' && a[i] <= '9'){
			b[a[i] - '0']++;
		}
	}
	for(int i = 9;i >= 0;i--){
		for(int j = 1;j <= b[i];j++){
			printf("%d" ,i);
		}
	}
	return 0;
} // #Shang4Shan3Ruo6Shui4
