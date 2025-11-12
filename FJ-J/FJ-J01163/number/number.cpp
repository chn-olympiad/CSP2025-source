#include<bits/stdc++.h>
using namespace std;

char s;
int a[1000001],i;

int main(){
	
	string s,i=1;
	scanf("%c",&s);
	m=s,length;
	for(int j=1;j<=m;j++){
		if(s[j]>='0'&&s[j]<='9'){
			a[i]=s[j]-'0';
			i++;
		}
	}
	i--;
	sort(a+1;a+i+1);
	for(int x=1;x<=i;m++)
		printf("%d",&a[x]);

	return 0;
}
