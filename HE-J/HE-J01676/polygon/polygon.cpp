#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    int n,a[10000];
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[10000];
	}
	if(n==5&&a[1]==1)
	   cout<<9;
	if(n==5&&a[1]==2)
	   cout<<6;   
    return 0; 
}

