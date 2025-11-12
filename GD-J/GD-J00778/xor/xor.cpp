#include<bits/stdc++.h>
using namespace std;
int n,k,d=0;
int x(int y,int z){
	return y||z-y&&z;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a[n],b[n],c[n],f[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int e=a[i];
		if(e==k){
			b[d]=i;
			c[d]=i;
			f[d]=1;
			d++;
		}
		for(int j=i;j<n;j++){
			e=x(e,a[j+1]);
			if(e==k){
				b[d]=i;
				c[d]=j+1;
				f[d]=j+2-i;
				d++;
			}
		}
	}
	for(int i=0;i<d;i++){
		for(int j=i+1;j<d;j++){
			if(f[i]>f[i+1]){
				int g=f[i];
				f[i]=f[i+1];
				f[i+1]=g;
			}
		}
	}
	int h=0,l=0;
	for(int i=0;;i++){
		l+=f[i];
		if(l>n){
			break;
		}
		h++;
	}
	cout<<h<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
