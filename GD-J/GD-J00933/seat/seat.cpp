#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
struct s{
	int t;
	int r;
}a[N];
bool cmp(s b,s c){
	return b.r>c.r;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l,r;
	cin>>n>>m;
	int nm;
	nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>a[i].r;
		a[i].t=i;
	}
	l=0;
	r=1;
	sort(a+1,a+1+nm,cmp);
	for(int i=1;i<=nm;i++){
		l++;
		if(l>n){
			l=1;
			r++;
		}
		if(a[i].t==1){
			cout<<r<<" "<<l;
			break;
		}
	}
	return 0;
} 
