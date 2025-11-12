#include <bits/stdc++.h>
using namespace std;
int a[1000005],o,p;
char s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=1;i<=s;i++){
	if(s>='0'&&s<='9'){
	o++;
	a[o]=s-'0';
	}
	}
	int k=0;
	for(int j=1;j<=o;j++){
	for(int i=1;i<=o;i++){
	if(a[i]>k){
	p=i;
	k=a[i];
	}
else continue;
	cout<<k;
	a[p]=0;
	}
}
return 0;
}
