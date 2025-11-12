#include<bits/stdc++.h>
using namespace std;
int a[15][15],n,m,rr;
int	cj[150];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int zong=n*m;
	for(int i=0;i<zong;i++){
		cin>>cj[i];
	}
	rr=cj[0];
	sort(cj,cj+zong,cmp);
	int k=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i%2==0){
				a[j][i]=cj[k];
				k++;			
			}else{
				a[n-j-1][i]=cj[k];
				k++;
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==rr) cout<<j+1<<" "<<i+1;
		}
	}
	return 0;
}
