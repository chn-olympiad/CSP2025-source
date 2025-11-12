#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
char s[maxn];
int tong[maxn];
bool isd(char x){
	if(x>='0' && x<='9') return true;
	else return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;i++){
		if(isd(s[i])){
			tong[int(s[i])-int('0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=tong[i];j++){
			printf("%d",i);
		}
	}
	return 0;
} 
