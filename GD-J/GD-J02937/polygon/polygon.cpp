#include<bits/stdc++.h>
#include<cstdio>

using namespace std;
int n, P = 998244353;
int a[5010];


int main(){
	freopen("polygon1.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	long long n;
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if(n == 3){
		if(a[1] + a[2] > a[3])cout << "1";
		else cout << "0";
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
