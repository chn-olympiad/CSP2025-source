#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5010];
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	sort(a,a+n);
	
	int z=a[n];
	int s=0,x;
	for(int i=0;i<n;i++){
		x+=a[i];
	}
	if(x>z*2){
		s++;
	}
	
	int h=0,j=1,k=2;
	while(h<n){
		z=a[k];
		x=a[h]+a[j]+a[k];
		if(x>z*2){
	    	s++;
		}
		h++;
		j++;
		k++;
	}
	
	int q=0,y=1,b=2,d=3;
	while(d<5){
		z=a[d];
		x=a[q]+a[y]+a[b]+a[d];
		if(x>z*2){
	    	s++;
		}
		q++;
		y++;
		b++;
		d++;
	}
	s=s%998;
	s=s%244;
	s=s%353;
	cout<<s;
	return 0;
}

