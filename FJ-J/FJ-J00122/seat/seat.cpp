#include<bits/stdc++.h>
using namespace std;
int a[150]={0};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>a[i];
	int mar=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==mar){
			cout<<i/n+1<<" ";
			if((i/n)%2==0) cout<<i%n+1;
			else cout<<m-i%n;
			break;
		}
	}
	return 0;
}
