#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int num[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int c=0,tmp;
	cin>>s;
	for(int i=0;s[i]!='\0';i++)
		if(s[i]>='0'&&s[i]<='9'){
			num[c]=s[i]-'0';
			c++;
		}
	for(int i=0;i<=c;i++){
		for(int j=0;j<=c;j++){
			if(num[j]<num[j+1]){
				tmp=num[j+1];
				num[j+1]=num[j];
				num[j]=tmp;
			}
		}
	}
	for(int i=0;i<c;i++) cout<<num[i];
	return 0;
}

