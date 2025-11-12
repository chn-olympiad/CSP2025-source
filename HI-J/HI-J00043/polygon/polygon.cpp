#include<bits/stdc++.h>
using namespace std;
int n;
int p[5678];
int v[5678];
long long cnt;
int st;
int l=0;
//void dfs(int b,int t){
	//for(int i=b;i<=n;i++){
		//if(v[i]==0&&b!=n){
			//l+=p[i];
			//v[i]=1;
			//if(l>2*p[i]&&t>=3){
				//cnt++;
				//cout<<l<<b<<endl;
			//}
			//dfs(i+1,t+1);
			//l-=p[i];
			
		//}
		
	//}
	//v[b]=0;
//}
int f(int k){
	int y=1;
	int s=1;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n-k;j++){
			y*=j; 
		}
		s+=y;
		y=1;
	}
	return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	sort(p+1,p+n+1);
	for(int i=3;i<=n;i++){
		cnt+=f(i);
		cnt=cnt%998244353;
		
	}
	cout<<cnt;
	return 0;
}
