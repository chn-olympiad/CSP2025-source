#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int t;
int n;

int a[100005][5]={};

int main(){
	cin>>t;
	while(t--){
		int ans =0;
		cin>>n;
		int maxs = n/2;
		for(int i = 1;i<=n;++i){
			for(int j = 1;j<=3;++j){
				cin>>a[i][j];
			}
		}
		
		for(int i = 1;i<=n;++i){
			ans += max(max(a[i][1],a[i][2]),a[i][3]);
		}
		cout<<ans<<endl;
	}	
	return 0;
}
