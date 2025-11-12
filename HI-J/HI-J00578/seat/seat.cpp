#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],x,y,j=0,c,r;
	double cc;
	cin>>n>>m;
	x=n*m;
	for(int i=0;i<x;i++) cin>>a[i];
	y=a[0];
	sort(a,a+x);
	for(int i=x-1;i>=0;i--){
		j++;
		if(a[i]==y){
				r=j%n;
				cc=(j+r)*1.0/n;
				c=(j+r)*1/n;
				if(cc-c>0){
					c++;
				}
				if(r==0){
					c--;
					r=n;
				}
				if(c==0){
					c++;
				}
				if(c%2==0){
					r=n-r+1;
					cout<<c<<" "<<r;
					break;
				}
				else if(c%2!=0){
					cout<<c<<" "<<r;
					break;
				}
		}
	}
	return 0;
}

