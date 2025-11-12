#include<bits/stdc++.h>
using namespace std;
struct f{
	int d,b,g,h,x,y;
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u[m],v[m],w[m],c;
	f a[n];
	int cnt=0;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}if(n>m){
			for(int j=0;j<m;j++){
				cnt=cnt+w[j];
			}
			cout<<cnt;
		
		}
	return 0;
}
