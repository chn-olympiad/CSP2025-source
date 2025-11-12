#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans=0,b[5005],y=0;
int ds(int cs,int x,int mx,int li){
	if(cs==n){
		
		return 0;
	}
	if(cs>=3&&x>(mx*2)){
		ans++;
	}
	
	for(int i=0;i<n;i++){
		if(a[i]>=li&&b[i]==0){
			b[i]=1;
		    if(a[i]>mx) mx=a[i];
		    x+=a[i];
		    cs++;
         	
			ds(cs,x,mx,a[i]);
  		    b[i]=0;
		}
	}
	return 0;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		y+=a[i];
	}
	sort(a,a+n);
	ds(0,0,0,0);
    if(y>(a[n-1]*2)){
		ans++;

	}
	ans=((ans%998)%244)%353;

	
	cout<<ans;
	return 0;
}

