#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[100005]={},p=0,n,m,j=1;
    bool sec=0;
    cin>>n>>m;
    for(int i=0;i<=n*m-1;i++){
    	cin>>a[i];
	}
	p=a[0];
    sort(a,a+n*m);
    int c=1,r=0;
    for(int i=n*m-1;i>=0;i--){
    	if(sec) r--;
    	if(!sec){
    		r++;
		}
		if(r<1){
			c++;
			r=1;
			sec=0;
		}
		if(r>n){
			c++;
			r=n;
			sec=1;
		}
    	//cout<<j<<" "<<a[i]<<" "<<c<<" "<<r<<endl; 
    	j++;
       	if(a[i] == p){
       		cout<<c<<" "<<r;
       		break;
		}
    }
    return 0;
}
