#include<bits/stdc++.h>
using namespace std;
const int N=1e3+1;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
	int n,m,e;
	int pp;
	cin>>n>>m;
	long long g[n*m];
	for(int i=0;i<n*m;i++){
		cin>>g[i];
		if(g[i]==0){
			g[i]=e;
		}
	}
	sort(g+N,g);
	
	for(int i=0;i<n*m;i++){
		if(g[i]==e){
			i=pp;
		}
	}for(int i=0;i<n;i++){
		if(pp-m>0){
		pp=pp-m;
		}else if(pp-m==0){
			if((i+2)%2==0){
				cout<<i<<" "<<1;
			}else{
				cout<<i<<" "<<m;
			}
		}else if(pp-m<0){
	if((i+1)%2==0){
				cout<<i-1<<" "<<m-pp;
			}else{
				cout<<i-1<<" "<<pp;
			}
		}		
	}
	
	
	
	return 0;
	
}
