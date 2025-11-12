#include<bits/stdc++.h>
using namespace std;

int n,m;
struct N{
	int id,w;
}a[114514];
bool cmp(N x,N y){
	return x.w>y.w;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int t;
		cin>>t;
		a[i].w=t;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int ix=1,iy=1,id=1;
	while(a[id].id!=1){
		if(iy%2==1){
			if(ix==n){
				iy++;
			}
			else ix++;
		}
		else if(iy%2==0){
			if(ix==1){
				iy++;
			}
			else ix--;
		}
		id++;
		
	}
	cout<<iy<<" "<<ix<<endl;
	return 0;
} 
