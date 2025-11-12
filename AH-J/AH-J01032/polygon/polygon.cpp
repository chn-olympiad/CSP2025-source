#include<bits/stdc++.h>
using namespace std;
int n,d,m,h,d1,m1,h1,a[5000],sum=0;
int abc(int i,int f){
	for(int x=f;x<=n-i+d+1;x++){
		if(d==i){
			if(h>2*m){
				sum+=1;
			}
			cout<<h<<" "<<m*2<<" "<<endl;
			d=d1;
			m=m1;
			h=h1;
			break;
		}
		else{
			m1=m;
			h1=h;
			d1=d;
			m=max(m,a[x]);
			h+=a[x];
			d+=1;
			f=x;
		abc(i,f+1);
		}
	}
	return 0;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		d=0;
		m=0;
		h=0;
		abc(i,0);
	}
	cout<<sum;
	return 0;
}
