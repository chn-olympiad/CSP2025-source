#include<bits/stdc++.h>
using namespace std;
int n,m,a[150],b[15][15],hs1=1,hs[15],ls[15],xr,s=1;
bool p(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		xr=a[1];
	}
	sort(a+1,a+n*m+1,p);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<" ";
//	}
//		cout<<endl;
	for(int i=1;i<=n*m;i++){
		ls[a[i]]=(i-1)/n+1;
		int e=i%n;
		if(s%2==1){
			hs[a[i]]=hs1;
			hs1++;
		}
		if(s%2==0){
			hs1--;
			hs[a[i]]=hs1;
		}
		if(e==0){
			s++;
		}
		//cout<<a[i]<<" "<<ls[a[i]]<<" "<<hs[a[i]]<<endl;
	}
	cout<<ls[xr]<<" "<<hs[xr];

	return 0;
}

