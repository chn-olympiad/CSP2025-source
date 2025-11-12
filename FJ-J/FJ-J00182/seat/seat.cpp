#include<bits/stdc++.h>

using namespace std;

int main(){

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int n,m;
	int a[105];
	
	cin>>n>>m;
	
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	
	int v=a[0];
	sort(a,a+n*m,[](int f,int e){
		return f>e;
	});
	
	int r=0;
	for(int i=0;i<n*m;i++){
		if(a[i]==v){
			r=i;
			break;
		}
	}
	
	int a5=r/n+1;
	int b=0;
	if(a5%2==1)b=r%n+1;
	else b=n-r%n;
	
	cout<<a5<<" "<<b;

	fclose(stdin);
	fclose(stdout);

	return 0;
}

