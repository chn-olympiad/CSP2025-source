#include<bits/stdc++.h>
using namespace std;
int n;
int solve(int x){
	for(int i = 1 ; i < x ; i++){
		x = (x*i)%998244353;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin >> n;
	cout << solve(n);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
