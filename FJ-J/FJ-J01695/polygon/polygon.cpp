#include<bits/stdc++.h>
#include<iostream>
using namespace std;
long long a[5005];
long long b[5005];
void f(int n,int c){
	if(n==0){
		return;
	}
	if(c!=0){
		for(int q=b[c-1]+1;q<n;q++){
			b[c]=q;
			n--;
			c++;
			f(n,c);
		}
	}
	else{
		for(int q=0;q<n;q++){
			b[c]=q;
			n--;
			c++;
			f(n,c);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	long long n,ma=-1,g=0;
	scanf("%d",&n);
	if(n==3){
		for(int q=0;q<n;q++){
			scanf("%d",&a[q]);
			ma=max(ma,a[q]);
			g+=a[q];
		}
		if(g>2*ma){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	for(int q=0;q<n;q++){
		scanf("%d",&a[q]);
	}
	for(int q=3;q<=n;q++){
		for(int w=0;w<n;w++){
			b[w]=0;
		}
		f(q,0);
		long long ma=-1,p=0;
		for(int w=0;w<q;w++){
			p+=b[w];
			ma=max(ma,b[w]);
		}
		if(p>2*ma){
			g++;
		}
	}
	printf("%d",g);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
