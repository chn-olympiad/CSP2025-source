#include<bits/stdc++.h>

using namespace std;

void bl(int* arr,int arrl){
	cout<<"arr:";
	for(int i=0;i<arrl;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,counter=0;
	cin>>n>>m;
	int seats[n*m];
	for(int i=0;i<n*m;i++){
		cin>>seats[i];
	}
	//bl(seats,n*m);
	int r=seats[0];
	sort(seats,seats+n*m,greater<int>());
	//bl(seats,n*m);
	for(int i=1;i<=m;i++){
		//cout<<"i="<<i<<endl;
		if(i%2==1){
			for(int j=1;j<=n;j++){
				//cout<<seats[counter]<<endl;
				if(seats[counter]==r){
					cout<<i<<" "<<j;
				}
				counter++;
			}
		} else {
			for(int j=n;j>=1;j--){
				//cout<<seats[counter]<<endl;
				if(seats[counter]==r){
					cout<<i<<" "<<j;
				}
				counter++;
			}
		}
	}
	return 0;
}
