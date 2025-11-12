#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int n,m,i,j=0,c,d;
	int a[10000];
	cin>>n>>m;
	for(i=0;i<n*m;i++){
		cin>>a[i];
		c=a[0];
		if(c<a[i]){
			j++;
		}
	}
	d=j/m+1;
	if(d%2!=0){
	cout<<d<<" "<<j%m+1;
    }
    else{
    	cout<<d<<" "<<m-j%m;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
