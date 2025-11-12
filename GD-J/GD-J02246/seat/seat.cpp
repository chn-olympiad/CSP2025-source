#include<bits/stdc++.h>
using namespace std;
const int N=15;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int r=0,c=0;
	for(int i=1;i<=n*m;i++){
		if(i%n==1){
			r++;
			int t=i/n;
			if(t%2==0) c=1;
			else c=n;
		}
		else c++;
		if(a[i]==x){
			cout<<r<<" "<<c;
			return 0;
		}
	}
	return 0;
}
