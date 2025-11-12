#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[100010];
	cin>>s;
	int a=strlen(s),b=0;
	char num[100010]={};
	for(int i=0;i<a;i++){
		if(s[i]>='0' && s[i]<='9'){
			num[b]=s[i];
			b++;
		}
	}
	for(int i=0;i<strlen(num);i++){
		for(int j=0;j<i;j++){
			if(num[j]<num[j+1]){
				char c=num[j];
				num[j]=num[j+1];
				num[j+1]=c;
			}
		}
	}
	for(int i=0;i<strlen(num);i++){
		cout<<num[i];
	}
	return 0;
}
