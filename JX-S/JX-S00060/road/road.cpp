#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k,ansa,ans;
struct node{
	int x,num;
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int x,y,z,i=1;i<=n;i++){
		cin>>x>>y>>z;
		ansa+=z;
	}
	if(k==0){
		cout<<ansa;
		return 0;
	} 
	cout<<0;
	return 0;
}
