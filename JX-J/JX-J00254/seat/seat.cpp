#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
	}
int n,m,a[110],sum;
int b;4 4
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	b=a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m,cmp);
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=1;j<=n;j++){
				if(a[sum]==b){
					cout<<i+1<<" "<<j;
					return 0;	
				}
				sum++;
			}	
		}
		if(i%2==1){
			for(int j=n;j>0;j--){
				if(a[sum]==b){
					cout<<i+1<<" "<<j;
					return 0;	
				}
				sum++;
			}	
		}
	}
	return 0;
}
