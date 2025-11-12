#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,max,maxj,s,c;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++)cin>>a[i];
	t=a[0];
	for(int i=0;i<n*m;i++){
		max=-1; 
		for(int j=i;j<n*m;j++){
			if(max<a[j]){
				max=a[j];
				maxj=j;
			}
		}
		if(max==t){
			s=i+1;
			break;
		}
		else {
			c=a[i];
			a[i]=max;
			a[maxj]=c;
		}
	}
	max=(s+n-1)/n;
	if(max%2==1){
		maxj=s%n;
		if(maxj==0)maxj=n;
	}
	else {
		maxj=n-s%n+1;
		if(maxj==n+1)maxj=1;
	}
	cout<<maxj<<" "<<max;
	
	return 0;
} 
