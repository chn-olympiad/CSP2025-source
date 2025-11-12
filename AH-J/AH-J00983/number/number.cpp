#include <bits/stdc++.h>
using namespace std;
int a[10];
char s[114514];
string sm[105];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<=105;i++){
		cin>>sm[i];
		for(int j=0;j<sm[i].size();j++){
		if(sm[i][j]<='9' && sm[i][j]>='0')a[sm[i][j]-'0']++;
	}
	if(sm[i].size()<4095)break;
	}
	
	for(int i=9;i>=0;i--)for(int j=1;j<=a[i];j++)cout<<i;
	
	return 0;
}
