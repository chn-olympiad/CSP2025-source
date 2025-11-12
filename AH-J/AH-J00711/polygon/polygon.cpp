#include<bits/stdc++.h>
using namespace std;
int f(int n){
	if(n==1){
		return 1;}
	int e=0;
	e+=n;
	return f(n-1)+e;
	}
int main(){
	int x;
	cin>>x;
	int a[x];
	int c=0,e=0,;
	for(int i=0;i<x;i++){
		cin>>a[i];
		}
		int u=f(x);	
		for(int j=0;j<u;j++){
			if(x>=j){
				for(int i=0;i<j;i++){
					for(int q=0;q<i;i++){
						c=a[j]+a[i]+a[q];
						if(c>2*max(a[q],a[i],a[j])){e++;}
					}
				}
			}
		}
		for(int j=0;j<u;j++){
			if(x>=j){
				for(int i=0;i<j;i++){
					for(int q=0;q<i;q++){
						for(int p=0;p<q;p++){
							c=a[j]+a[i]+a[q]+a[p];
							if(c>2*max(a[q],a[i],a[j],a[p])){e++;}
						}
					}
				}
			}
		}
		for(int j=0;j<u;j++){
			if(x>=j){	
				for(int i=0;i<j;i++){
					for(int q=0;q<i;q++){
						for(int p=0;p<q;p++){
							for(int l=0;l<p;l++){
								c=a[j]+a[i]+a[q]+a[p]+a[l];
								if(c>2*max(a[q],a[i],a[j],a[p],a[l])){e++;}
							}
						}
					}
				}
			}
		}
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cout<<e;
	return 0;
	}
