#include<bits/stdc++.h>
using namespace std;
long long n,k[200005][4];
long long sum=-1;
void dfs(int xh,int q,int w,int e,long long my){
	if(xh>n){
		sum=max(sum,my);
		return;
	}
	for(int i=1;i<=3;i++){
		int p;
		if(i==1&&q<n/2){
			p=my+k[xh][1];
			dfs(xh+1,q+1,w,e,p);
		}else if(i==2&&w<n/2){
			p=my+k[xh][2];
			dfs(xh+1,q,w+1,e,p);
		}else if(i==3&&e<n/2){
			p=my+k[xh][3];
			dfs(xh+1,q,w,e+1,p);
		}
	}
}
int main(){
 	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
 	int t;
 	cin>>t;
 	while(t--){
 		sum=-1;
 		cin>>n;
 		for(int i=1;i<=n;i++){
 			cin>>k[i][1]>>k[i][2]>>k[i][3];
		}
		dfs(1,0,0,0,0);
		cout<<sum;
	}
 	return 0;
}
