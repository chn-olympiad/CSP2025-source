#include<bits/stdc++.h> 
using namespace std;

int lis[120];

int main(){
	float n,m;
	float pm=1;
	cin>>n>>m;
	cin>>lis[0];
	for(int i=1;i<n*m;i++){
		cin>>lis[i];
		if(lis[i]>lis[0]){
			pm++;
		}
	}
	int fn=0;
	int fm=ceil(pm/n);
	if(fm%2==1){
		fn=pm-(n*fm)+n;
	}
	else{
		fn=n-(pm-(n*fm)+n)+1;
	}
	cout<<fm<<' '<<fn;
	return 0;
}
