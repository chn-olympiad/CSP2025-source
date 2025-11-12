#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int num[10];
char c[(int)(1e6+10)];
bool null=true;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	scanf("%s",c);
	int len=strlen(c);
	for(int i=0;i<len;i++)
	{
		if(c[i]>='0'&&c[i]<='9'){
			num[(int)(c[i]-'0')]++;
			if(null&&c[i]!='0') null=false;
		}
	}
	if(null) putchar('0');
	else
		for(int i=9;i>=0;i--){
			for(int j=0;j<num[i];j++){
				putchar((char)('0'+i));
			}
		}
	return 0;
}
