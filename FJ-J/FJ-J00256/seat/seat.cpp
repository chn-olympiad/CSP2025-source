#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[100000010];
int x=0,y=1;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int l=n*m;
	for(int i=1;i<=l;i++){
		cin>>a[i];
	}
	int num=a[1];
	sort(a+1,a+l+1,cmp);
/*/
/*/
	for(int i=1;i<=l;i++){
		if(i<=n){
			x++;}
		if(i>n){
			if(i%n==0){
				y=i/n;
			}
			else{
				y=(i/n)+1;
			}
		}
		if(y%2==0){
			if(i%n==0){
				x=1;
			}
			if(i%n!=0){
				x=n-(i%n)+1;	
			}	
		}
		if(y%2!=0){
			if(i%2!=0){
				x=i%n;	
			}
			if(i%2==0){
				x=i-n*(y-1);	
			}	
		}
		if(a[i]==num){
			cout<<y<<" "<<x;
			return 0;
		}
	}
	return 0;
} 
