#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int a,t;
}arr[105];
bool cmp(node x,node y){
	return x.a>y.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>arr[i].a;
	}
	arr[0].t=1;
	sort(arr,arr+(n*m),cmp);
	for(int i=0;i<n*m;i++){
		if(arr[i].t==1){
			k=i;
			break;
		}
	}
	k++;
	int ml=k/n+1;
	if(k%n==0)ml--;
	cout<<ml<<' ';
	int nl;
	if(k%n==0)nl=n;
	else nl=k%n;
	if(ml%2==0){
		nl=n-nl+1;
	}
	cout<<nl;
	return 0;
}