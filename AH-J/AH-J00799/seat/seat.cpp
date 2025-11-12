#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int x;
int i;
int j;
int f;
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			x=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	i=1;
	j=1;
	f=1;
	for(int k=1;k<=n*m;k++){
		if(a[k]==x){
			cout<<j<<" "<<i;
			return 0;
		}
		else{
			if(f==1){
				i=i+1;
				if(i>n){
					i=n;
					j=j+1;
					f=(f+1)%2;
				}
			}
			else{
				i--;
				if(i<1){
					i=1;
					j=j+1;
					f=(f+1)%2;
				}
			}
		}
	}
	cout<<m<<" "<<n;
	return 0;
}
