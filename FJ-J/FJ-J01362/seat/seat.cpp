#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],w,q1,q2,exam,l,r;
bool cmp(int a,int b){
	return a>b;
} 
int frond(int x){
	int mid;
	while(l<r){
		mid=(l-r)/2;
		if(a[mid]=x){
			return mid;
		}else if(a[mid]<x){
			l=mid;
		}else{
			r=mid;
		}
	}
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","r",stdout);
	for(int i=1;i<=n*m;i++) cin>>a[i];
	cin>>n>>m;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++)exam=a[i];
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	cout<<endl;
	w=frond(exam);
	r=m*n;
	r=frond(exam);
	if(w%n==0)q1=w/n;
	else q1=w/n+1;
	cout<<q2<<" ";
	if(q1%2==1){
		q2=w%n;
		if(q2==0)q2+=n;
	} 
	else q2=n-w%n+1;
	cout<<q1<<" "<<q2;
}
