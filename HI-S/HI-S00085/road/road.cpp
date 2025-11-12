#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1005][3];
int b[1005][1005];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	
	for(int i=0;i<m;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	
	for(int i=0;i<k;i++){
		int cnt=0;
		cin>>b[i][0];
		cnt+=b[i][0];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
			cnt+=b[i][j];
		}
		if(cnt==0){
			cout<<0;
		}
	}
	
	return 0;
}

