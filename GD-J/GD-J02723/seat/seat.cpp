#include <bits/stdc++.h>
using namespace std;
int arr[105],s[105][105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k=1,w=0,q=0,p=0;
	cin>>n>>m;
	w=n*m;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
	}
	q=arr[1];
	sort(arr,arr+w+1);
	for(int i=1;i<=n*m;i++){
		if(arr[i]==q){
			p=i;
			break;
		}
	}
	p=w-p+1;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
			s[i][j]=k;
			if(s[i][j]==p){
				cout<<i<<" "<<j;
				return 0;
			}
			k++;
		}
		}else{
			for(int j=n;j>=1;j--){
			s[i][j]=k;
			if(s[i][j]==p){
				cout<<i<<" "<<j;
				return 0;
			}
			k++;
		}
		}
		
	}
	
	
	
	
	return 0;
}
