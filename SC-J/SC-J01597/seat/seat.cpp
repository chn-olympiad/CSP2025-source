#include<bits/stdc++.h>
using namespace std;
int n,m,sum,l=0,r=1;
int num;
int a[15][15],b[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>b[i];
	}
	num=b[1];
	sort(b+1,b+sum+1);
	for(int i=sum;i>=1;i--){
		if(((sum-i-1)/n)%2==0){
			l++;
		}
		else{
			l--;
		}
		if(l>n){
			l=n;
			r++;
		}
		if(l<1){
			l=1;
			r++;
		}
	    if(b[i]==num){
			cout<<r<<' '<<l;
		}
	}
	return 0;
}