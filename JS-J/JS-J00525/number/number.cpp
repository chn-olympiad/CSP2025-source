#include<bits/stdc++.h>
using namespace std;
int cnt;
char a[1000005];
int b[10];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for(auto x:s){
		if(isdigit(x))b[x-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<b[i];++j){
			cout << i ;
		}
	}
}
