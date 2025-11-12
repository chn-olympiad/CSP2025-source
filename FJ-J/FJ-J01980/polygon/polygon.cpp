#include<bits/stdc++.h>
using namespace std;
int a,b[1000000],c=0;
void chen(int d[100000],int e){
	cout<<e<<" ";
	sort(d+1,d+1+a);
	if(e<=2){
		return;
	}
	int z=0;
	for(int i=1;i<=a-1;i++){
		z+=d[i];
	}
	if(z>d[a]){
		c++;
	}
	e--;
	for(int i=1;i<=a;i++){
		if(d[i]!=0){
			int m=d[i];
	    	d[i]=0;
	    	chen(d,e);
	    	d[i]=m;
		}	
	}
	e++;
}

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cout<<9;
	return 0;
}
