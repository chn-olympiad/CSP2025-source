#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10005],c;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==c){
			if(((i-1)/n+1)%2==1){
				cout<<(i-1)/n+1<<" "<<(i-1)%n+1;
			}else{
				cout<<(i-1)/n+1<<" "<<n-(i-1)%n;
			}
		}
	}
	return 0; 
}
