#include<iostream>
#include<cmath>
using namespace std;
int a[101],s[11][11],r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++)
		cin>>a[i];
	for(int i=1;i<=k;i++)
		for(int j=i+1;j<=k;j++)
			if(a[i]<a[j]){
				swap(a[i],a[j]);
				if(i==1)
					r=j;
			}
	int c=floor((r-1)/n)+1;
	if(c%2!=0){
		r%=n;
		if(r==0)
			r=n;
	}
	else
		r=1+c*n-r;;
	cout<<c<<" "<<r;
    return 0;
}
