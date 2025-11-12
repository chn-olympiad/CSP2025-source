#include<bits/stdc++.h>
using namespace std;
int a[12][12],b[105],n,m,z; 
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>b[i];
		if(!i)z=b[i];
	}
	int cnt=0;
	sort(b,b+n*m,cmp);
	for(int i=0;i<n;i++){
		if(!(i%2)){
			for(int j=0;j<m;j++){
				a[i][j]=b[cnt++];
				if(a[i][j]==z){cout<<i+1<<' '<<j+1<<' '<<'\n';return 0;}
			}
		}
		else{
			for(int j=m-1;j>=0;j--){
				a[i][j]=b[cnt++];
				if(a[i][j]==z){cout<<i+1<<' '<<j+1<<' '<<'\n';return 0;}
			}
		}
	}
} 
