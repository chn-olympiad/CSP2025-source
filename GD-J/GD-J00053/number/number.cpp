#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(cnt,0,sizeof(cnt));
	scanf("%s",a);
	for(int i=0;a[i];i++){
		if('0'<=a[i]&&a[i]<='9') cnt[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]){
			printf("%d",i);
			cnt[i]--;
		} 
	} 
	return 0;
}

