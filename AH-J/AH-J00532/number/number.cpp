#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int x=0;
char s[10010],a[10010];
cin.getline(s,10010);
int len=strlen(s);
for(int i=0;i<len;i++){
	if(s[i]<='9'&&s[i]>='0'){
		a[x]=s[i];
		x+=1;
	}
}
sort(a,a+x);
for(int i=x-1;i>=0;i--){
	cout<<a[i];
}
return 0;
}
