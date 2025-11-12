#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c=1,r=1,score,flag;
	cin>>n>>m>>flag;
	for(int i=0;i<n*m-1;i++){
		cin>>score;
		if(score>flag){
			if((r%n==0 and c%2==1) or
			(r==1 and c%2==0)){
				if(++c%2==0) r=n;
				else r=1;
			}
			else {
				if(c%2==0) r--;
				else r++;
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}

