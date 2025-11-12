#include<bits/stdc++.h>
using namespace std;
int a[100],n;
inline int dfs(int top,int z,int g){
	if(n-top==1&&g<3)return 0;
	if(n-top==1&&2*z<=a[top+1])return 0;
	if(n-top==1)return 1;
	int sum=0;
	sum+=dfs(top+1,z,g);
	sum+=dfs(top+1,z+a[top],g+1);
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int b[n];
	for(int i=0;i<n;i++)cin>>b[i];
	
	sort(b,b+n);
	for(int i=0;i<n;i++)a[i]=b[i];
	int sum=dfs(0,0,0);
	cout<<sum;
	return 0;
}
