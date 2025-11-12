#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char c[N];
int n,a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&c);
	int siz=strlen(c);
	for(int i=0;i<siz;i++)
		if(c[i]>='0'&&c[i]<='9') a[++n]=c[i]-'0';
	sort(a+1,a+1+n,cmp);
	if(a[1]==0) cout<<0;
	else{
		for(int i=1;i<=n;i++) printf("%d",a[i]);
	}
	return 0;
}
