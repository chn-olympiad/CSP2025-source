#include <bits/stdc++.h>
using namespace std;
int n,m,t,x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int z=n*m;
	int a[z];
	for(int i=0;i<z;i++){
		cin>>a[i];
		if(i==0) t=a[i]; 
	}
	sort(a+1,a+z+1);
	for(int i=z;i>=0;i++){
		if(t==a[i]){
			x=z-i+1;
			break;
		}
	}
	int w=1,h=1;
	h+=x;
	if(h>m){
		w-=1-h;
		h=1;
	}
	if(w>n){
		h+=w-n;
		w=n;
	}
	cout<<n<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
