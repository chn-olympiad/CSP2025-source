#include<bits/stdc++.h>
using namespace std;
int n,m,num=1;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) num++;
	}
	cout<<num<<"\n";
	int h,l;
	if(num%m==0){
		l=num/n;
	    if((num/n)%2==1) h=n;
		else h=1;
	}else{
		l=(num/n)+1;
		if(l%2==1) h=num%m;
		else h=n-num%m+1;
	}
	cout<<l<<" "<<h<<"\n";
    return 0;
}
