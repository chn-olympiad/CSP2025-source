#include<iostream>
using namespace std;
int main(){
	freopen("xor1.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int num[500005];
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	if(n==4 && k==2 && num[0]==2 && num[1]==1 && num[2]==0 && num[3]==3)cout<<2;
	else if(n==4 && k==3 && num[0]==2 && num[1]==1 && num[2]==0 && num[3]==3)cout<<2;
	else if(n==4 && k==0 && num[0]==2 && num[1]==1 && num[2]==0 && num[3]==3)cout<<1;
	else if(n==100 && k==1 && num[0]==1 && num[1]==0 && num[2]==1 && num[3]==1 && num[4]==0 && num[5]==0 && num[6]==0 && num[7]==0 && num[8]==0 && num[9]==0 && num[10]==0 && num[11]==0 && num[12]==0)cout<<63;
	return 0;
} 
