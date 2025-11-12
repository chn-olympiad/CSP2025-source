#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int n,a[10010],maxx=0,sum=0,x,b=0;
cin>>n;
for(int i=1;i<=n;i++){
	 cin>>a[i];
}
for(int i=1;i<=n;i++){
	for(int c=1;c<=n;c++){
		for(int j=i;j<=i+c;j++){
		    sum+=a[j];
		    maxx=max(maxx,a[j]);
		    x=maxx*2;
		    if(j==i+c&&j-i>=3&&sum>x)b++;
	    }maxx=0;sum=0;
    }
}
cout<<b%998244353;
return 0;
}
