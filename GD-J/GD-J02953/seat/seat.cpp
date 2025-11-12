#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m+1];
    cin>>a[0];
    int R=a[0];
    for(int i=1;i<n*m;i++){
        cin>>a[i];
    }
    sort(a,a+n*m);
    int number;
    for(int i=0;i<n*m;i++){
    	if(a[i]==R){
    		number=n*m-i;
    		break;
		}
	}
	int x=number/n;
	int y=number%n;
	if(y!=0){
		x+=1;
	}
	else{
		y=n;
	}
	if(x%2==0){
		y=n-y+1;
	}
	cout<<x<<" "<<y;
return 0;
}


