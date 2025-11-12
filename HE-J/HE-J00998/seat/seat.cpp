#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],s[1000],r,l,h;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		r=a[1];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			if(i%n==0){
				l=i/n;
				if(l%2==0){
					h=1;
				}
				else{
					h=n;
				}
			}
			else{
				l=i/n+1;
				if(l%2==0){
					h=n-i%n+1;
				}
				else{
					h=i%n;
				}
			}
			break;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
