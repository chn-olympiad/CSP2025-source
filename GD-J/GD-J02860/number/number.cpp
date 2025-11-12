#include<bits/stdc++.h>
using namespace std;
char a[100000005];
int n[100000005];
int s=1;
int len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=strlen(a);i++)
	{
		if(a[i]=='1') n[++len]=1;
		if(a[i]=='2') n[++len]=2;
		if(a[i]=='3') n[++len]=3;
		if(a[i]=='4') n[++len]=4;
		if(a[i]=='5') n[++len]=5;
		if(a[i]=='6') n[++len]=6;
		if(a[i]=='7') n[++len]=7;
		if(a[i]=='8') n[++len]=8;
		if(a[i]=='9') n[++len]=9;
		if(a[i]=='0') n[++len]=0;
		
	}
	sort(n+1,n+len+1);
	for(int i=len;i>=1;i--) cout<<n[i];
	
	return 0;
}
