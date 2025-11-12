#include<bits/stdc++.h>
using namespace std;
const int K=150;
int n,m,score,id,seat[K];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)cin>>seat[i];
	score=seat[1];
	sort(seat+1,seat+n*m+1,cmp);
	for(int i=1;i<=n;++i){
		if(i%2){
			for(int j=1;j<=m;++j){
				id=n*(i-1)+j;	
				if(seat[id]==score){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=m;j>=1;--j){
				id=n*i-m+j;
				if(seat[id]==score){
					cout<<i<<" "<<m-j+1;
					return 0;
				}
			}
		}
	}
	return 0;
}

