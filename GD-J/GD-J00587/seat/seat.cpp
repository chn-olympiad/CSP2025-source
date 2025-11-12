#include<bits/stdc++.h> 
using namespace std;
int a[1000];
bool cmp(int a,int b){
	return (a>b);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int a1=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n;i++){
		if((i+1)%2==1){
			for(int j=0;j<m;j++){
				if(a[i*m+j]==a1){
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}
		}
		else{
			for(int j=0;j<m;j++){
				if(a[i*m+j]==a1){
					cout<<i+1<<" "<<m-j;
					return 0;
				}
			}
		}
	}
	return 0;
}
//ÃëÀ±£¡£¡£¡*2 

