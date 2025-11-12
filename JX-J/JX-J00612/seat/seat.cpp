#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat3.in","r",stdin);
	freopen("seat3.out","w",stdout);
	int n,m,a[1000],x=1,y=1;
	bool b=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[1]<a[i]){
			
			if(b==0){
				x++;
				}
			if(b==1){
				y++;
				b=0;
				break;
				}
			if(x==n){
				b=1;
				}
			}
		}
	cout<<y<<" "<<x;
	
	
	
	
	
	
	return 0;
}
