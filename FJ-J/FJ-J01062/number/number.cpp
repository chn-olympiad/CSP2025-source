#include<bits/stdc++.h>
using namespace std;

int t[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char ch;
	while(cin>>ch) if('0'<=ch&&ch<='9') t[ch-'0']++;
	for(int i=9;i>=0;i--) while(t[i]--) printf("%d",i);
	return 0;
}
