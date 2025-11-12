#include<bits/stdc++.h>
using namespace std;
int t;
int n;
//int m[100001][5];
int max(int c);
int use[4]={0};

int max(int c){
	int maxn=m[c][1];
	for(int i=1;i<=3;i++){
		if(m[c][i]>=maxn && use[i]<n/2){
			maxn=m[c][i];
			use[i]+=1;	
		}
	}
	return maxn;
}

int main(){
	freopen("club.in",r,stdin);
	freopen("club.out",w,stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		int sum=0;
		cin>>n;
		int m[n+1][5];
		int ans[n] 
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>m[j][k];
			}
		}
		for(int j=1;j<=n;j++){
			sum+=max(j);
		}
		ans[i]=sum;
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
