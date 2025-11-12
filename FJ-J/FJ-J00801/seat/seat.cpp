#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,w;
}s[105];
bool cmp(node a,node b){
	return a.w>b.w;
}
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i].w;
		s[i].id=i;
	}
	sort(s+1,s+n*m+1,cmp);
	int zw=0;
	for(int i=1;i<=n*m;i++){
		if(s[i].id==1){
			zw=i;
		}
	}
	int h=0,l=0;
	h=zw/n;
	if(zw%n!=0) h++;
	l=zw%n;
	if(l==0) l=n;
	if(h%2==0){
		l=n-l+1;
	}
	cout<<h<<" "<<l;
	return 0;
} 
