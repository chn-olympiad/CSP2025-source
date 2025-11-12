#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k,u,l,h;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
	    cin>>a[i];
	    u=a[0];
    }
    sort(a,a+n*m+1);
    for(int i=n*m;i>0;i--){
        k++;
		if(a[i]==u)break;
    }
    h=(k-1)/m+1;
    cout<<h<<" ";
    if(h%2==0){
        cout<<m-(k-m*(h-1))+1;
    }else{
        cout<<k-m*(h-1);
    }
    return 0;
}
