#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,res,l,r,f;
struct node{
	int sum;
	int num;
}a[N];
bool cmp(node x,node y){
	return x.sum>y.sum;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){cin>>a[i].sum; a[i].num=i;}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1){
			res=i;
			break;
		}
	}
	l=res/n;
	f=res%n;
	if(f!=0) l++;
	if(l%2!=0){
		if(f==0) r=n;
		else r=f;
	}
	else{
		if(f==0) r=1;
		else r=n-f+1;
	}
	cout<<l<<" "<<r;
	return 0;
} 
