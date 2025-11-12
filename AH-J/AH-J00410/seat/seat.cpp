#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r,s,o=1;
    cin>>n>>m;
    cin>>r;
    for(int i=1;i<n*m;i++){
	cin>>s;
	if(s>r)o++;	
	}
	int l=o/n,h;
	if(o%n==0){
		if(l%2==0){
		cout<<l<<" "<<1;
	}
	else{
   cout<<l<<" "<<n;	
	}
		
	}
	else{
	if(l%2==0){
	h=o-l*n;	
	}
	else{
	h=n-(o-l*n)+1;	
	}
	cout<<l+1<<" "<<h;	
	}
    return 0;
}
