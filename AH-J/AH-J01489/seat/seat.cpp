#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>arr[i];
	}int a=arr[0];
	sort(arr,arr+n*m);
	int l=1,k=1;
	if(arr[n*m-1]==a){
		cout<<k<<" "<<l;
		return 0;
	}
	for(int i=n*m-2;i>=0;i--){
		if(k%2==0){
			if(l==1) k++;
			else l--;
		}else{
			if(l==m) k++;
			else l++;
		}if(arr[i]==a){
			cout<<k<<" "<<l;
			return 0;
		}
	}
}
