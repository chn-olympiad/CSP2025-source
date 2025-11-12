#include<bits/stdc++.h>
using namespace std;

int n,m;
char a[n];
int b[100008];
int ans = 0;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>b[i];
	}
	
	for(int i = 1;i <= n;i++){
		if(b[i] > b[i+1]){
			ans += 1;
		}else{
			if(b[i] < b[i+1]){
				ans += 2;
			}
		}
	}
	
	cout<<ans;
	
	
	return 0;
}
