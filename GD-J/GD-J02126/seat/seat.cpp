#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],nowi,x,y;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		cin>>a[i];
	for(int i=n*m/2+1;i>0;i--)
		for(int j=0;i+j<n*m;j++)
			if(a[j]<a[i+j]){
				swap(a[j],a[i+j]);
				if(j==nowi) nowi=i+j;
				else if(i+j==nowi) nowi=j;
			}
	/*for(int i=0;i<n*m;i++)
		cout<<a[i]<<" ";
	cout<<nowi;*/
	x=nowi/n;
	y=nowi%n;
	if(x%2==0){
		cout<<x+1<<" "<<y+1;
	}
	else{
		cout<<x+1<<" "<<m-y+1;
	}
	return 0;
} 
