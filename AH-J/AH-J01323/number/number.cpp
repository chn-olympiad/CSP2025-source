#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int b[1000005];
bool cmp(int a,int b){
	return a>b;
	}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>a;
int w=0;
int len=strlen(a);
for(int i=0;i<len;i++){
	if(a[i]<='9'&&a[i]>='0'){
		b[++w]=a[i]-'0';
		}
	}
	sort(b+1,b+w+1,cmp);
	bool k=0;
	for(int i=1;i<=w;i++){
		if(b[i]!=0)k=1;
		if(k)cout<<b[i];
		}
return 0;
}
