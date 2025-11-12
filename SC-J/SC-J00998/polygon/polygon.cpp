#include<bits/stdc++.h>
using namespace std;
int n,a[5005],t=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	    cin>>a[i];
	sort(a,a+n);
	int b=0,z=2,c=2;
	for(int i=0;i<n-2;i++){
		for(int o=0;o<z;o++)
			    b=a[0]+b;
	    for(int j=z;j<n;j++){
		    if(b>a[j]){
			   t++;
		    }else{
		    	b=0;
		    	z++;
		    	break;
		    }
		    if(j==n){
		    	b=0;
		    	z++;
		    	break;
		    }
		}
	}
	cout<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
}