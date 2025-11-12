#include<bits/stdc++.h>
using namespace std;
int t,n[100010];
int main(){
	preopen("club.in","r",stdin);
	preopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=i;j++){
			cin>>n[i][j];
		}
	}
	return 0;
}
