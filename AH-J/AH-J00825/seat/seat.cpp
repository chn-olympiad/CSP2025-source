#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a1;
    int seat;
    int p=0;
    int n,m;
    cin>>n>>m;
    int alist[n*m]={};
    int k=0;
    for(int i=0;i<n*m;i++){
        int a;
        cin>>a;
        if(k==0){
            a1=a;
        }
        alist[i]=a;
        k++; 
    sort(alist);
    for(int j=0;j<n*m;j++){
		p++;
		if(alist[j]==a1){
			seat=p;
			break;
		}
	}
	if((seat/n+1)%2==0){
	    int c=seat/n+1;
	    int r=n+1-seat%n;
	}
	else if((seat/n+1)%2==1){
		int c=seat/n+1;
	    int r=seat%n;
	}
	cout<<c<<r;    
    return 0;
}
