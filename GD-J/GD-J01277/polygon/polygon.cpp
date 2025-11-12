#include<bits/stdc++.h>
using namespace std;
int n,a[5005],r,s[5005],v[5005],sum;
void ff(int t,int g){
	int m=0,l=0;
	for(int i=0;i<r;i++){
		m=max(m,s[i]);
		l+=s[i];
	}
	cout<<l<<" "<<m<<endl;
	if(2*m<l&&r>2){
		sum++;
	}
	if(t>=n){
		return;
	}
	for(int i=g;i<n;i++){
		if(v[i]==0){
			s[r]=a[i];
			r++;
			v[i]=1;
			ff(t+1,i);
			r--;
			v[i]=0;
		}
	}
}
int main(){
	/*
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	*/
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	ff(0,0);
	cout<<sum;
	return 0;
}
