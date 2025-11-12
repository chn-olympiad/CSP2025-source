#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],tot;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char ch;
	while(cin>>ch){
		if(ch>='0'&&ch<='9') a[++tot]=ch-'0';
	}
	sort(a+1,a+1+tot,cmp);
	for(int i=1;i<=tot;i++) cout<<a[i];
	return 0;
}
