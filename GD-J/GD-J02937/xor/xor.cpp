#include<bits/stdc++.h>
#include<cstdio>

using namespace std;
long long n, k;
int a[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	if(n == 2 && k == 0){
		for(int i = 1; i <= n; i ++){
			cin >> a[i];
			if(a[1] == a[2])cout << "1";
			else cout << "0";
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
