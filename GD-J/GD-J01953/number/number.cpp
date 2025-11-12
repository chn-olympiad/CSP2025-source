#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[10010]={' '};
	int i=0,j=0,a[10010];
	scanf("%s",&s);
	while(s[i]!=' '){
		if( s[i]=='0' or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9' or s[i]=='1'){
			a[j]=int(s[i])-48;
			j++;
		}
		i++;
	}
	sort(a,a+j);
	for(int i=j-1;i>=5;i--){
		printf("%d",a[i]);
	}
	return 0;
	}
