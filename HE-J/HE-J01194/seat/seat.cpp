#include<bits/stdc++.h>
using namespace std;
int n,m,b=1,z,k;
struct qwe{
	int x,y;
}v[1010];
bool qwer(qwe q,qwe w){
	return q.x>w.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>v[i].x;
		if(i==1){
			v[i].y=1;
		}
	}sort(v+1,v+1+n*m,qwer);
	for(int i=1;i<=m;i++){
		if(b==1){
			for(int j=b;j<=n;j++){
				if(v[++k].y==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=b;j>=1;j--){
				if(v[++k].y==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		if(b==1){
			b=n;
		}else{
			b=1;
		}
	}
	return 0;
}
