#include<bits/stdc++.h>
using namespace std;
int a[5000];
int n;
int wyydj(int Max,int sum,int x){
	int ans=0;
	if(x>n)return 0;
	if(Max*2<sum)ans++;
	ans+=wyydj(Max,sum,x+1);
	ans+=wyydj(max(Max,a[x]),sum+a[x],x+1); 
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<max(0,wyydj(0,0,0)-2)<<endl;
	return 0; 
} 
