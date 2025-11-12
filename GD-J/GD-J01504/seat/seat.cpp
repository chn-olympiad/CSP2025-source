#include<bits/stdc++.h>
using namespace std;
bool cmd(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int tc;
	cin>>tc;
	int a[10001]={0};
	a[1]=tc;
	
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		
	} 
	sort(a+1,a+n*m+1,cmd);
	int c,r;
	for(int i=1;i<=n*m;i++){
		if(a[i]==tc){
			c=(i/n)+1;
			if(c%2){
				r=i%n;
				if(r==0){
					r=1;
					c--;
				}	
			}
			else{
				r=n-(i%n)+1;
				if(r>n){
					c--;
					r=n;
				}
			}
			break;
		}
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
