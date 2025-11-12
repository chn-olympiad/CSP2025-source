#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],c[N];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0) c[i]=0;
		else if(a[i]==1) c[i]=1;
		else if(a[i]==2) c[i]=10;
		else if(a[i]==3) c[i]=11;
		else if(a[i]==4) c[i]=100;
		else if(a[i]==5) c[i]=101;
		else if(a[i]==6) c[i]=110;
		else if(a[i]==7) c[i]=111;
		else if(a[i]==8) c[i]=1000;
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}