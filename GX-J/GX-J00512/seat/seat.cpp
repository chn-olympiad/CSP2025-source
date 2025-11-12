#include<bits/stdc++.h>
using namespace std;
int a[130];
bool cmp(int i,int j){
	return i>j;
}
int main(){
	int i,k,n,m;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	k=a[1];
	for(i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	for(i=1;i<=n*m;i++){
		if(a[i]==k){
			int l=(i-1)/n,r;
			l++;
			if(l%2==0){
				r=n-(i%n)+1;
			}
			else{
				r=((i-1)%n)+1;
			}
			cout<<l<<" "<<r;
			break;
		}
	}
	return 0;
}
