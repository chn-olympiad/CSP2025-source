#include<bits/stdc++.h>
using namespace std;
long long a[100001];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int w=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==w){
			int x=ceil(i*1.0/n);
			cout<<x<<" ";
			if(x%2==1){
				cout<<i%n;
				return 0;
			}else {
				cout<<n-x%n;
			}
		}
	}
	return 0;

