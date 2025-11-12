#include<bits/stdc++.h>
using namespace std;
int n,m;
int seat[105]={0};
//bool f=1;
int main(){
	freopen("seat.in","r1",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int Rstu=0;
	for(int i=1;i<=n*m;i++){
		cin>>seat[i];
	}
	Rstu=seat[1];
	sort(seat+1,seat+n*m+1);
	int j=1,k=1;
	for(int i=n*m;i>=1;i--){	
		//cout<<i<<" " <<j<<" "<<k<<endl;
		if(i==1){
			cout<<j<<" "<<k<<endl;
			return 0;
		}
		if(i%m==1&&i!=n*m){
			if(j%2==1){
				k=m;
			}
			j++;
			//cout<<"bbb"<<endl;
		}
		if(seat[i]==Rstu){
			//cout<<i<<endl;
			cout<<j<<" "<<k<<endl;
			return 0;
		}
			if(j%2==1||j==1){
				k++;
			}else if(j%2==0){
				k--;	
			}
		
	}
	return 0;
}
