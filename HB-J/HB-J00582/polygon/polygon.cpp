#include<bits/stdc++.h>
using namespace std;
int n,a[5002],gdl,zh=0;
bool used[5002]={0};
void dfs(int k,int z){
	int h,f=0;
	for(int j=0;j<=(z-1)*(k-1)-k*z){
		for(int i=0;i<=k-1;i++){
			h+=a[i];
		}
		if(h>a[k-1] && used[k-1]==0){
			used[k-1]=1;
			f++;
			used[k-1]=0;
		}
	}
	return f;
}
int main(){
  freopen("polygon.in","r",stdin);
  cin>>n;
  for(int i=0;i<=n-1;i++){
  	cin>>a[i];
  	if(a[i]>a[i-1] && i!=0){
  		gdl=a[i-1];
  		a[i-1]=a[i];
  		a[i]=gdl;
  	}
  }
  for(int i=3;i<=n;i++){
  	zh+=dfs(i,z);
  }
  cout<<zh;
  freopen("polygon.out","w",stdout);
  return 0;
}
