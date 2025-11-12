#include<bits/stdc++.h>
using namespace std;
struct data{
	int s,e,w;
}arr[100001];
int n,m,k,num;

bool cmp(data a1,data a2){
	return a1.w<a2.w;	
}

int main()
{
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k; 
		for(int i=1;i<=m;++i){
			cin>>arr[i].s>>arr[i].e>>arr[i].w;	
			num+=arr[i].w;
		}
		cout<<num;
	return 0;
 } 
