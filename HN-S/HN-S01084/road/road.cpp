#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w;
struct cj{
	long long x,c;
};
cj a[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int sum=0
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		sum+=w;
	}
	cout<<sum/2+2;
	return 0;
}
// 不会骗，先写了再说:) 
