#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,a[20];char c[N]; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c+1);n=strlen(c+1);
	for(int i=1;i<=n;i++)if(c[i]>='0'&&c[i]<='9')a[c[i]-'0']++;
	for(int i=9;i>=0;i--)for(int j=1;j<=a[i];j++)printf("%d",i);
	return 0;
}