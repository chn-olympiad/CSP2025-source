#include<iostream>
using namespace std;
feopen("seat.in","r",stdin);
feopen("seat.out","w",stdout);
int main(){
    int n,m,a[105];
    cin>>n>>m;
    for(int =1;i<=n*m;i++){
    	cin>>a[i];
    }
    sort();
    int sum=;a=0;b=0;
    while(sum==){
    	while(b==4){
    	    if(sum==){
    	        break;
    	    }
            b++;
            sum++;
    	}
    	a++;
    	while(b==1){
    	    if(sum==){
    	        break;
    	    }
    	    b--;
    	    sum++;
    	}
    	a++;
    }
    cout<<a<<b;
    return 0;
}
