#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("saet.out","w",stdout);
	int n,m;
	int r=0;
	int a[106]={};
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	r+=a[0];
	int s[105][105]={};
	for(int i=m;i<=1;i++){
		if(i%2==1){
			for(int j=0;i<n;i++){
				s[j][i]+=a[i];
			}
		}else{
			for(int z=n;z>=1;z--){
				s[z][i]+=a[i];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==r){
				//cout<<s[i][j];
			}
		}
	}
	return 0;
} 