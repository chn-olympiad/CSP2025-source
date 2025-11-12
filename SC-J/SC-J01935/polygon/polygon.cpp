#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int l[5001];
bool cmp(int p,int q){
	return p>q;
}
int f(int e,int s){
	int z=0,h=0;
	for(int k=s;k<n;k++){
		h=0;
		for(int k1=k;k1<n;k1++){
			h+=l[k1];
		}
		if(h>e){
			
			z+=f(e-l[k],k+1);
		}
		if(l[k]>e){
			
			z++;
		}	
	}
	return z;
}
int main(){
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	sort(l,l+n,cmp);
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			m=l[i]-l[j];
			r+=f(m,j+1);
		}
	}
	cout<<r;
	return 0;
}