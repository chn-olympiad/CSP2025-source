#include<bits/stdc++.h>
using namespace std;
int q(int a,int b){
	int c[30],d=0,num=0;
	if(a<b){
		swap(a,b);
	}
	while(a!=0){
		if(a%2!=b%2){
			c[d]=1;
			a=a/2;
			b=b/2;
		}else{
			c[d]=0;
			a=a/2;
			b=b/2;
		}
		d++;
	}
	for(int i=d-1;i>=0;i--){
		num=num*2+c[i];
	}
	return num;
}
long long n,k,o=1,p=1,c,m=0,mo,mp;
int a[500009];
int main(){
	freopen("xol.in","r",stdin);
		freopen("xol.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		c=a[i]; if(c==k&&mp>=i){
				m=1;
				mo=i;
				mp=i;
			}
		for(int j=i+1;j<=n;j++){
			c=q(c,a[j]);
			if(c==k&&(j-i)>m){
				m=j-i;
				mo=i;
				mp=j;
			}

		}
	}
cout<<m;
	return 0;
}
