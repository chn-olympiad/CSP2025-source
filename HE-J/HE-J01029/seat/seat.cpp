#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,a[1005];
	int R;
	int Q;
	int cnt=1,jia=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		R=a[1];   //СR
		if(n==1 && m==1){
			cout<<"1"<<" "<<"1"; 
		}else if(n==1 && m<=10){
			if(a[i]>a[1]){
				cnt++;
				Q=1;
			}
		}else if(n>=10 && m==1){
			if(a[i]>a[1]){
				jia++;
				Q=2;
			}
		}
	}
	if(Q=1){
		cout<<cnt<<" "<<"1";
	}else if(Q=2){
		cout<<"1"<<" "<<jia;
	}
	return 0;
} 
