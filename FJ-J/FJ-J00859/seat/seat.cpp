#include<bits/stdc++.h>
using namespace std;
int a[100100];
bool cmp(int c,int b){
	return c>b;
};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m;
	cin>>n;
	cin>>a[1];
	int sum =a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	int p;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum) p=i;
	}
	int d= p%n;
	if(d==0) {
		cout<<p/n<<" ";
		int j=p/n;
		if(j%2==1){
			cout<<n<<" ";
		}
		else cout<<1;
		
	}
	else{
		int y=p/n;
		int z=y+1;
    	 cout<<z<<" ";
		if(z%2==1){
			cout<<d;
		}
		else{
			cout<<n-d+1<<" ";
		} 
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
    
}
	
