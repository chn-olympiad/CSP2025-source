#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	char ch;
	while(cin>>ch)if(ch>='0'&&ch<='9')a[ch-'0']++;
	for(int i = 9;i>=0;i--)for(int j = 1;j<=a[i];j++)cout<<i;
	return 0;
}
