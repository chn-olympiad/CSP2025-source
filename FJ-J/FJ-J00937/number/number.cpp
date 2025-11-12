#include<bits/stdc++.h>
using namespace std;
int jl[15];
char a[1000005];
int lena;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	lena=strlen(a);
	for(int i=0;i<lena;i++)if('0'<=a[i]&&a[i]<='9')jl[a[i]-'0']++;
	for(int i=9;i>=0;i--)for(int j=1;j<=jl[i];j++)cout<<i;
	return 0;
}

