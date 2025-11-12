#include<bits/stdc++.h>
using namespace std;
int arr[10000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num,place,cnt=1,ansn=1,ansm=1,times=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		if(i==1){
			cin>>num;
			arr[i]=num;
		}
		else{
			cin>>arr[i];
		}
		if(arr[i]>num){
			cnt++;
		}
	}
	while(1){
		if(cnt-n>0){
			cnt-=n;
			ansn++;
		}
		else{
			
			break;
		}
	}
	cout<<ansn<<" "<<cnt; 
	return 0;
} 
