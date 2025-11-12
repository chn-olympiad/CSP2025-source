#include<bits/stdc++.h>
#include<iostream>
using namespace std;
long long n,t;
long long a[100005][5],b[100005][5],p=-1,h;
long long o,i,j,l;
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	long long n[t+5];
	for(o=1;o<=t;o++){
		cin>>n[o];
		for(i=1;i<=n[o];i++){
			for(j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>p){
					p=a[i][j];
				} 
			}
			h=h+p;
		}
		cout<<h<<endl;
		h=0;
		p=-1;
		
	}return 0;
} 
