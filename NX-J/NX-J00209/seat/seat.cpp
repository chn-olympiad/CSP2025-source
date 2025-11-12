#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int arr[n*m+10];
	int chji;
	for(int i=0;i<n*m;i++){
		cin>>arr[i];
		if(i==0)chji=arr[i];
	}
	for(int i=0;i<n*m;i++){
		for(int j=i+1;j<n*m;j++){
			if(arr[i]<arr[j]){
				int x=arr[i];
				arr[i]=arr[j];
				arr[j]=x;
			}
		}
	}
	int hang=0;
	int lie=1;
	for(int i=0;i<=n*m;i++){
		if(lie%2==1 && hang==m){
			lie++;
			continue;
		}else if(lie%2==0 && hang==1){
			lie++;
			continue;
		}
		if(lie%2==1){
			hang++;
		}else if(lie%2==0){
			hang--;
		}
		if(chji==arr[i]){
			cout<<lie<<" "<<hang;
			return 0;
		}
	}
	return 0;
}
