#include<bits/stdc++.h>
using namespace std;
char a;
int b[1000100],j=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a)if(isdigit(a))b[j++]=a-'0';
	sort(b,b+j);
	for (int i=j-1;i>=0;i--)cout<<b[i];
	return 0;
}
