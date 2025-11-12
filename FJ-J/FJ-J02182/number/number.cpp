#include<bits/stdc++.h>
using namespace std;
char s[100005];
int num[100005],k;
int main(){
//	freopen ("number.in","r",stdin);
//	freopen ("number.out","w",stdout);
	scanf("%s",s);
	int len=strlen(s);
	for(int i=1;i<=len;i++){
		if('0'<=s[i] && s[i]<='9'){
			num[k]=s[i]-'0';
			k++;
		}
	}
	sort(num,num+k);
	if(num[k-1]==0){
		cout<<0;
		return 0;
	}
	for(int i=k-1;i>=0;i--){
		cout<<num[i];
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
