#include<bits/stdc++.h>
using namespace std;
struct club{
	int ii,jj,kk;
}cl[100005];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int t;
	cin>>t;
	while(t--){
		long long maxx=0;
		int n,id;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>cl[i].ii>>cl[i].jj>>cl[i].kk; 
			if(cl[i].ii>maxx){
				maxx=cl[i].ii;
				id=i; 
			}
		}
		if(n==2)
			cout<<max(max(cl[1].ii+cl[2].jj,cl[1].ii+cl[2].kk),max(cl[1].jj+cl[2].ii,max(cl[1].jj+cl[2].kk,max(cl[1].kk+cl[2].ii,cl[1].kk+cl[2].jj)))) ;
		else{
			long long maxn=0;
			for(int i=1;i<=n;i++){
				if(cl[i].ii>maxn&&id!=i){
					maxn=cl[i].ii;
				}
			}
			cout<<maxx+maxn;
		}
	}
	return 0;
} 
