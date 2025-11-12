#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],flag,c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int mun=m*n;
	flag=1;
    for(int i=1;i<=mun;i++){
		for(int j=mun;j>i;j--){
		    if(a[j]>a[i]){
				if(i==flag) flag=j;
				else if(j==flag) flag=i;
				swap(a[i],a[j]);
			}
	    }
	}
	if(flag%n==0){
		c=flag/n;
	}
	else c=1+flag/n;
	int rt=flag%(2*m);
	if(rt>m){
		if(rt-m==1) r=m;
	}
	else if(1<=rt&&rt<=m) r=rt;
	else if(rt==0) r=1;
    return 0;
}
