#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n;
int a[N][5];
int vis[N][5];
int mx=INT_MIN;
int sum;
int c[5]={0};
bool cmp(int a,int b){return a>b;}
void dfs(int i){
	if(i>n){
		mx=max(mx,sum);
		return;
	}
	for(int k=1;k<=3;k++){
		if(c[k]+1<=n/2&&vis[i][k]==0){
			vis[i][k]=1;
			c[k]++;
			sum+=a[i][k];
			dfs(i+1);
			vis[i][k]=0;
			c[k]--;
			sum-=a[i][k];
		}
		else continue;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<N;i++){
			a[i][1]=0;a[i][2]=0;a[i][3]=0;
		}
		int ok=1;
		for(int i=0;i<n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3]; 
			if(a[i][2]!=0||a[i][3]!=0)ok=0;
		}
		vector<int>a1;
		for(int i=0;i<n;i++)a1.push_back(a[i][1]);
		sort(a1.begin(),a1.end(),cmp);
		if(ok==1){
			int ret=0; 
			for(int i=0;i<n/2;i++)ret+=a1[i];
			cout<<ret;
		}
		else{
			mx=INT_MIN;sum=0;c[1]=0;c[2]=0;c[3]=0;
			for(int i=0;i<n;i++){
				vis[i][1]=0;vis[i][2]=0;vis[i][3]=0;
			}
			dfs(0);
			cout<<mx<<"\n";
		}
	}
	return 0;
}
