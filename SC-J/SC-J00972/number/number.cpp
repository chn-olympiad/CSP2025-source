#include<bits/stdc++.h>
using namespace std;

const int N=1e6+7;
char a[N];
int t[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a+1);
	int len=strlen(a+1);
	for(int i=1;i<=len;i++){
		if(a[i]<='9'&&a[i]>='0'){
			t[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(t[i]){
			printf("%d",i);
			t[i]--;
		}
	}
	return 0;
}