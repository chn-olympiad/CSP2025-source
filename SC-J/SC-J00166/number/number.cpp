#include<bits/stdc++.h>

using namespace std;
char c[1000010];
int num[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>(c+1);
	int len=strlen(c+1);
	for(int i=1;i<=len;i++){
		if(c[i]>='0'&&c[i]<='9'){
			num[c[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++){
			cout<<i;
		}
	}
	return 0;	
} 