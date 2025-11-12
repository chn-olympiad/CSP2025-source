#include<bits/stdc++.h>
using namespace std;
int o[105],n,m,a[109],w,k,q=1,ww=1,ji=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
		o[a[i]]++;
		if(i==1)w=a[i];
	}
	for(int i=100;i>=0;--i){
		if(o[i]!=0)
		if(w==i)break;
		else{
			if(ji==0)
			    if(ww==m)q++,ww=m,ji=1;
			    else ++ww;
			else {
				if(ww==1)q++,ww=1,ji=0;
			    else --ww;
			}
		}
	}
	cout<<q<<" "<<ww;
	return 0;
} 
