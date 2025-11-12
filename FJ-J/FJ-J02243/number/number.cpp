#include<bits/stdc++.h>
using namespace std;

int n;
char s[1000010];
int dat[1000010];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >>s;
	int k = sizeof(s);
	for(int p = 0; p <= k; p ++){
		int m = s[p]-'0';
		if(0 <= m && m <= 9){
			n ++;
			dat[n] = m;
		}
	}
	//cout <<n;
	//for(int i = 1; i <= n; i ++) cout <<dat[i];
	sort(dat+1, dat+n+1);
	for(int i = n; i >= 1; i --) cout <<dat[i];
	//cout <<" " <<n;
	
	return 0;
}
