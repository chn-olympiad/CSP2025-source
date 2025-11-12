#include<bits/stdc++.h>
using namespace std;
int n,m,a[200];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int x=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int sum=0;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				sum++;
				if(a[sum]==x){
					cout<<i<<" "<<j;
				}
			}
		}
		else{
			for(int j=m;j>=1;j--){
				sum++;
				if(a[sum]==x){
					cout<<i<<" "<<j;
				}
			}			
		}
	}
	return 0;
} 
