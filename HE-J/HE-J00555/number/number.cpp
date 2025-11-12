#include <bits/stdc++.h> 
using namespace std;
int a[1000005]={0};
char s[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k=0;
	scanf("%s",s+1);
	int len=strlen(s+1);
	if(len==1){
		cout<<s[1]-'0';
		return 0;
	}
	for(int i=1;i<=len;i++){
		int b=s[i]-'0';
		if(b>=0&&b<=9){
			a[i]=b;
			k++;
		}
	}
	sort(a+1,a+len+1);
	for(int i=len;i>=len-k+1;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

