#include<bits/stdc++.h>
using namespace std;

int n,vis[10];

bool bl=1;

string s;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	n=s.length();
	for(int i=0;i<=9;i++) vis[i]=0;
	for(int i=0;i<=n;i++){
		char tmp=s[i];
		if('0'<=tmp&&tmp<='9') vis[tmp-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(i==0&&bl){
			cout << '0';
			break;
		}
		for(int k=1;k<=vis[i];k++){
			cout << i;
			bl=0;
		}
	}
	return 0;
}
