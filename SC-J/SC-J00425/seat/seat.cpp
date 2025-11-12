#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int r[n*m],b[n*m],ma=-1,w=0,s[n][m],mm,mn;
	for(int i=0;i<n*m;i++){
		cin>>r[i];
	}
	//输入 
	for(int i=0;i<n*m;i++){
		ma=-1;
		for(int j=0;j<n*m;j++){
			if(r[j]>ma){
				ma=r[j];
				w=j;
			}
		}
		r[w]=0;
		b[i]=w;
	}
	//排序 
	int fx=0;
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			if(fx==0){
				s[j][i]=b[j*n+i];
				if(b[j*n+i]==0){
					mm=j+1;
					mn=i+1;
				}
			}
			if(fx==1){
				s[j][i]=b[j*n+n-1-i];
				if(b[j*n+n-1-i]==0){
					mm=j+1;
					mn=i+1;
				}
			}
		}
		if(fx==0) fx=1;
		else fx=0;
	}
	//列表 	
	cout<<mm<<" "<<mn;
	return 0;
}
