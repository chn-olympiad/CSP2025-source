#include<bits/stdc++.h>
using namespace std;
int n,m,r,rs=0,a[103],hang,lie,re=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]==100)
			re=i;
	}
	r=a[1];
	for(int t=r;t<=100;t++)
		for(int i=1;i<=n*m;i++)
			if(a[i]==t)
				rs++;
	lie=rs/n+1;
	if(rs%n==0)
		lie-=1;
	rs=rs+n-n*lie;
	if(lie%2==1){
		hang=rs;
	}
	else{
		hang=n-rs+1;
	}
	cout<<lie<<" "<<hang;
	return 0;
} 
