#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	int s=n*m,a[100];
	for(int i=0;i<s;i++){
			cin>>a[i];	
	}
	sort(a+1,a+s);
	int ans=1,i=s-1;
	while(a[i]>a[0]){
		ans++;
		i--;
	}
	int c,r;
	c=(ans-1)/n+1;
	if(c%2) r=(ans-1)%n+1;
	if(c%2==0) r=n-(ans-1)%n;
	cout<<c<<" "<<r<<endl; 
	return 0;
}
