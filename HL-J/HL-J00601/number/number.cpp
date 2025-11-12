#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
char a[1000005];
int b[15];
int ni;
int n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=(strlen(a)-1);i++){
		if((a[i]>='a')&&(a[i]<='z')){
			continue;
		}
		ni=a[i]-'0';
		b[ni]++;
	}
	for(int i=9;i>=0;i--){
		while(b[i]!=0){
			cout<<i;
			b[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
