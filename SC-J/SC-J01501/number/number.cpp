#include<bits/stdc++.h>
using namespace std;
char s[100010];
int f;
int c[100010];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=strlen(s)-1;
	sort(s,s+n+1,cmp);
	for(int i=0;i<=n;i++){
		if(s[i]>='0' && s[i]<='9') cout<<s[i];
	}
	return 0;
}