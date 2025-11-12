#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100],s,d=1,f,c,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		s=a[1];
		if(a[i]<a[i+1]){
			f=a[i];
			a[i]=a[i+1];
			a[i+1]=f;
		}
	}
	sort(a.begin()+1,a.end()+1);
	cout<<c<<" "<<r;
return 0;
 } 
 
 
 
 

