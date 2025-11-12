#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],k=0,s;
bool cop(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
			cin>>a[i];
			if(i==0){
				s=a[i];
			}
	}
	sort(a,a+n*m,cop);
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=1;j<=n;j++){
				if(a[k]==s){
					cout<<i+1<<" "<<j;
					return 0; 
				}
				k++;
			}
		}
		if(i%2==1){
			for(int j=n;j>0;j--){
				if(a[k]==s){
					cout<<i+1<<" "<<j;
					return 0; 
				}
				k++;
			}
		}
	}
	return 0;
} 
