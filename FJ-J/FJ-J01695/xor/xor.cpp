#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
long long a[500005];
bool b[500005]={0};
int xoor(int a,int b){
	bool a1[25]={0},b1[25]={0},c1[25]={0};
	long long p=20;
	while(a>0){
		if(pow(2,p)<=a){
			a-=pow(2,p);
			a1[p]=1;
		}
		p--;
	}
	p=20;
	while(b>0){
		if(pow(2,p)<=b){
			b-=pow(2,p);
			b1[p]=1;
		}
		p--;
	}
	for(int q=0;q<25;q++){
		if(a1[q]!=b1[q]){
			c1[q]=1;
		}
		else{
			c1[q]=0;
		}
	}
	long long l=0;
	for(int q=0;q<25;q++){
		if(c1[q]==1){
			l+=pow(2,q);
		}
	}
	return l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,p=0;
	scanf("%d",&n);
	scanf("%d",&k);
	for(int q=0;q<n;q++){
		scanf("%d",&a[q]);
	}
	for(int r=0;r<n;r++){
		for(int q=0;q<n-r;q++){
			long long w=q+r;
			bool lsg=0;
			long long p1=0;
			for(int e=q;e<=w;e++){
				if(b[e]==1){
					lsg=1;
					break;
				}
				if(e==q){
					p1=a[e];
				}
				else{
					p1=xoor(p1,a[e]);
				}
			}
			if(lsg==0){		
				if(p1==k){
					p++;
					for(int e=q;e<=w;e++){
						b[e]=1;
					}
				}
			}
		}
	}
	printf("%d",p);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
