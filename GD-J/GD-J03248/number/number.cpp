#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int arr[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	for(int i = 0;s[i] != '\0';i++)
		if(s[i] >= '0' && s[i] <= '9')
			arr[s[i]-'0']++;
	for(int i = 9;i >= 0;i--){
		while(arr[i] > 0){
			arr[i]--;
			printf("%d",i);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
