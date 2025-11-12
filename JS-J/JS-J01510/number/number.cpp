#include<bits/stdc++.h>
using namespace std;
long long cnt[15]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000000];
	bool flag=0;
	scanf("%s",&s);
	int k=0;
	while(s[k]!=0){
		k++;
	}
	for(int i=0;i<=k;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt[s[i]-'0']++;
			if(s[i]!='0') flag=1;
		}
	}
	if(!flag){
		printf("0");
		return 0;
	} 
	for(int i=9;i>=0;i--){
		while(cnt[i]){
			printf("%d",i);
			cnt[i]--;
		}
	}
	return 0;
}
