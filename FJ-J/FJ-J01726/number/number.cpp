#include<bits/stdc++.h>
using namespace std;
int a[1000005],n,b,c,d,e,f,g,h,j,k;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>n; 
    for(int i=1;i<=n;i++){
    	cin>>a[n];
    	if(a[i]==1){
			b++;
		}else if(a[i]==2){
			c++;
		}else if(a[i]==3){
			d++;
		}else if(a[i]==4){
			e++;
		}else if(a[i]==5){
			f++;
		}else if(a[i]==6){
			g++;
		}else if(a[i]==7){
			h++;
		}else if(a[i]==8){
			j++;
		}else{
			k++;
	    }
	}

	for(int i=1;i<=k;i++){
		cout<<9;
	}
	for(int i=1;i<=j;i++){
		cout<<8;
	}
	for(int i=1;i<=h;i++){
		cout<<7;
	}
	for(int i=1;i<=g;i++){
		cout<<6;
	}
	for(int i=1;i<=f;i++){
		cout<<5; 
	} 
	for(int i=1;i<=d;i++){
		cout<<4;
	}
	for(int i=1;i<=e;i++){
		cout<<3;
	}
	for(int i=1;i<=c;i++){
		cout<<2;
	}
	for(int i=1;i<=b;i++){
		cout<<1;
	}
	return 0;
} 
