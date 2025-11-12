#include<bits/stdc++.h>
using namespace std;
int ans[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin >> a;
	for(int i = 0 ; i < a.size() ; i++){
		if(a[i] >= '0' && a[i] <= '9'){
			ans[a[i] - '0']++;
		}
	}
	for(int i = 9 ; i >= 0 ; i--){
		while(ans[i]){
			cout << i ;
			ans[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
} 
