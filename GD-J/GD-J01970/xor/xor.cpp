#include<bits/stdc++.h>
using namespace std;

//map <int , vector<int> > M;

int H[200005][200005];



int dp[200005];

int n,k,a[200005];
int input[200005];


void init(){
	
	for(int L = 1; L <= n; L++){
		
		H[L][L] = input[L];
		
		for(int R = L + 1; R <= n; R++){
			
			H[L][R] = H[L][R-1] ^ input[R];
			
		}
	}
	
	
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k ;
	
	for(int i = 1;i <= n; i++){
		cin>>input[i];
	}
	
	init();
	
	for(int i = 1; i <= n; i++){
		
		for(int p = i; p >= 1; p--){
			
			int t = 0;
			if(H[p][i] == k){
				t = 1;
			}
			
			dp[i] = max(dp[i] , dp[p-1] + t);
			
		}
		
	}
	
	cout << dp[n] << '\n';
	
	return 0;
}
