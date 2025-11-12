#include<bits/stdc++.h>
using namespace std;
int a[101];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	int id=0;
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				id++;
				if(a[id]==k){
					cout<<i<<" "<<j;
					return 0;
				}
				
			}
		}
		else{
			for(int j=m;j>=1;j--){
				id++;
				if(a[id]==k){
					cout<<i<<" "<<j;
					return 0;
				}
				
			}
		}
	}
	return 0;
}
