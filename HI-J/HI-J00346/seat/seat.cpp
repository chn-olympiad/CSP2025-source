#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001];
vector<long long s[10001][1001]>;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	} 
	sort(a[1],a[n*m]);
	int ans=1;
	for(int l=1;l<=n;l++){
		for(int j=1;j<=m;j++){
			 s[l][j]=a[ans];
			 ans++;
		}
	}
	for(int h=1;h<=n;h++){
		for(int k=1;k<=m;k++){
			if(a[1]==s[h][k]){
				cout<<s[h][k];
				break;
			}
		}
	}
	return 0;
}
