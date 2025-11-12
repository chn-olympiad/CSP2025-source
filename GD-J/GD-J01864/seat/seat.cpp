#include<bits/stdc++.h> 
using namespace std;
int n,m,arr[105],idx[15][15],cnt=0,k;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>arr[i];
	k=arr[0];
	sort(arr,arr+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				idx[i][j]=arr[cnt];
				if(arr[cnt]==k){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				idx[i][j]=arr[cnt];
				if(arr[cnt]==k){
					cout<<i<<" "<<j;
					return 0;
				}
				cnt++;
			}
		}
	}
	return 0;
}
