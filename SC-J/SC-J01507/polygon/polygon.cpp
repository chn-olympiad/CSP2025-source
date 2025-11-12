#include<bits/stdc++.h>
using namespace std;
int a[100000],b[100000],book[100000],pro,sum,nn;
void dfs(int step,int n){
	if(step==n+1){
		int sun=0;
		for(int i=1;i<=n-1;i++){
			sun+=b[a[i]];
			if(sun>b[a[n]]){
				sum++;
				break;
			}
		}
		return ;
	}
	for(int i=1;i<=nn;i++){
		if(book[i]==0&&i>a[step-1]){
			a[step]=i;
			book[i]=1;
			dfs(step+1,n);
			book[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>nn;
	for(int i=1;i<=nn;i++) cin>>b[i];
	for(int i=3;i<=nn;i++){
		dfs(1,i);
	}	
	cout<<sum<<endl;
}