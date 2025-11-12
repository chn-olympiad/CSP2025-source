#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int R;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	R=a[1];
	int x;
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==R){
			x=i;
			break;
		}
	}
	int a=1,b=1,z=1;
	for(int i=1;i<x;i++){
		if(i%n==0){
			b++;
			z=-z;
		}else{
			a+=z;
		}
	}
	cout<<b<<" "<<a;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
