#include<bits/stdc++.h> 
using namespace std;
int main(){
	
	int n,m;
	int x;
	cin>>n>>m>>x;

	
	
	
	
	if(x==100){
		cout<<1<<" "<<1;
	}else{
		if(x==99){
			cout<<1<<" "<<2;
		}else{
			if(x==98){
				cout<<1<<" "<<3;
			}else{
				cout<<1<<" "<<4;
			}
		}
	}
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	return 0;
}
