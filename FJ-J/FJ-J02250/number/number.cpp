#include<iostream>
#include<cstring>
using namespace std;
const int N=1e6+5;
int n;
int cnt[15];
char a[N];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a+1);
	n=strlen(a+1);
	for(int i=1;i<=n;i++){
		if(a[i]>=48&&a[i]<=57) cnt[a[i]-48]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++) printf("%d",i);
	}
	return 0;
}

