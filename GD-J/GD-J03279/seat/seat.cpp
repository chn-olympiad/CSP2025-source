#include <bits/stdc++.h>
using namespace std;
const int N=15,M=15;
int n,m;
int s[N*M];
int c,r,w,k;
bool cmp(int x,int y){
	return x>y;
}
int find(int x){
	int l=1,r=n*m;
	while(l<=r){
		int mid=(l+r)/2;
		if(s[mid]==x)
			return mid;
		else if(s[mid]<x)
			r=mid-1;
		else
			l=mid+1;
	}
}
int main(){
	freopen("seat2.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>s[1];
	w=s[1];
	for(int i=2;i<=n*m;i++)
		cin>>s[i];
	sort(s+1,s+n*m+1,cmp);
	k=find(w);
	c=(k-1)/n+1;
	if(c%2==0)
		r=n-(k-1)%n;
	else
		r=(k-1)%n+1;
	cout<<c<<" "<<r<<endl;
	return 0;
}
