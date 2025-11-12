#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a[3304]={};
	int k,num,h,l;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	k=0;num=0;h=0;l=0;
	k=a[0];
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==k){
			num=n*m-i;break;
		}
		
	}//cout<<num;
	h=num%n;l=num/n;
	if(num%n>0) l++;
	
	if(l%2==1){
		if(h==0)h=n;
		cout<<l<<" "<<h;	
	}
	else{
		if(h==0)
		cout<<l<<" "<<1;
		else
		cout<<l<<" "<<h+1;
	}
	
	//cout<<num;
	return 0;
}
