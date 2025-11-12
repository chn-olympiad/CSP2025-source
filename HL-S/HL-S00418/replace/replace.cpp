#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n=0,q=0;
	cin >> n >> q;
	string s[n][2] = {}
	int ans = 0;
	int answer[101] = {};
	for(int pos=0;pos<q;pos++){
		
		
		
		for(int i=0;i<n;i++){
			for(int j=0;j<2;j++){
				cin >>s[i][j];
			}
		}
		
		answer[pos] = ans;
		
	} 
	
	for(int pos=0;pos<q;pos++){
		cout << answer[pos] <<endl; 
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
