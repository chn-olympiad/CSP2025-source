#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=110;
int n,m,num;
int c,r;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			if(i%n!=0) c=i/n+1;
			else c=i/n;
			if(c%2==0&&i%n!=0){
				r=n+1-i%n;
			}else if(c%2!=0&&i%n!=0){
				c=i/n+1;
				r=i%n;
			}else if(c%2==0&&i%n==0){
				c=i/n;
				r=1;
			}else if(c%2!=0&&i%n==0){
				c=i/n;
				r=n;
			}
		}
		
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
