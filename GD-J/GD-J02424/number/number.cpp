//number.cpp
#include<stdio.h>
#include<algorithm>

char s[(int)1e6],ans[(int)1e6];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&s);
	int num=0;
	for(int i=0;i<sizeof(s);i++){
		if(s[i]>='0' && s[i]<='9'){
			ans[num]=s[i];
			num++;
		}
	}
	std::sort(ans,ans+num);
	for(int i=num-1;i>=0;i--){
		printf("%c",ans[i]);
	}
	return 0;
}
