#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100010][4];
int ans,s1,s2,s3;
int maxn;
int b[100010];
int f1,f2,f3;
void dfs(int x,int ans){
	if(x==n+1){
		if(ans>maxn)maxn=ans;
	}
	if(s1<n/2){s1++;dfs(x+1,ans+a[x][1]);s1--;}
	if(s2<n/2){s2++;dfs(x+1,ans+a[x][2]);s2--;}
	if(s3<n/2){s3++;dfs(x+1,ans+a[x][3]);s3--;}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		maxn=s1=s2=s3=0;
		f1=f2=f3=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]!=0)f1=0;
			if(a[i][2]!=0)f2=0;
			if(a[i][3]!=0)f3=0;
		}
		if(f2==1&&f3==1){
			for(int i=1;i<=n;i++){b[i]=a[i][1];}
			sort(b+1,b+1+n,greater<int>());
			int anss=0;
			for(int i=1;i<=n/2;i++)anss+=b[i];
			cout<<anss<<endl;
			continue;
		}
		dfs(1,0);
		cout<<maxn<<endl;
	}
}
