#include<bits/stdc++.h>
using namespace std;
int a[15][15],n,m,p[105],sum=0,k=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;//n为行，m为列 
	k=n*m;
	for(int i=0;i<k;i++){
		cin>>p[i];
	}
	sum=p[0];
	sort(p,p+k);
	//p[n*m-1]或p[k-1]是最大的QAQ 
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				if(p[k-1]==sum){
					cout<<i+1<<" "<<j+1;
					return 0;
				} else{
					k--;
				}
			}
		}else{
			for(int j=n-1;j>=0;j--){
				if(p[k-1]==sum){
					cout<<i+1<<" "<<j+1;
					return 0;
				} else{
					k--;
				}
			}
		}
	}
	return 0;	
} 
