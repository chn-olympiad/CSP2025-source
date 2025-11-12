#include<iostream>
#include<cstring>
using namespace std;
char s[1000001]; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s + 1); 
	int a[1000001];
	int n = 0;
	int l = strlen(s + 1);
	for(int i = 1;i <= l;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			n++;
			a[n] = s[i] - 48;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			if(a[j] > a[i]){
				swap(a[i],a[j]); 
			}
		}
	}
	for(int i = 1;i <= n;i++){
		printf("%d",a[i]);
	}
	return 0;
}