#include<bits/stdc++.h>
using namespace std;
bool cmp(char x,char y){
	if(x>='0'&&x<='9'&&y>='0'&&y<='9') return x>y;
	return x<y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000005];
	cin>>a;
	int l=strlen(a);
	sort(a,a+l,cmp);
	for(int i=0;i<l&&a[i]>='0'&&a[i]<='9';i++) cout<<a[i];
	return 0;
}
