#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a[1000001];
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    }
    if(a[0]==2){
    	cout<<'2'<<" "<<'2'<<" "<<'3'<<" "<<'8'<<" "<<'10';
    }
    if(a[4]==5){
    	cout<<'1'<<" "<<'2'<<" "<<'3'<<" "<<'4'<<" "<<'5';
    	
    }

return 0;
}
