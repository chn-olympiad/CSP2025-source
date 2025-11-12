#include<bits/stdc++.h>
using namespace std;
int n,m;
int c,r;
int a[100005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1];
	int num;
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++){
		if(a[i]==k){
		   num=i;
		   break;
		} 
	}
	if(num<=m){
	    cout<<"1"<<" "<<num;
	}
	else{
	    c=num%m;
	    r=(num-c)/m+1;
	    if(r%2==0){
			cout<<r<<" "<<m-c+1;
	    }
	    else if(r%2!=0){	
	        cout<<r<<" "<<c;
		}
	}
}
