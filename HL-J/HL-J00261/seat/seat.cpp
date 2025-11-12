#include<bits/stdc++.h>
using namespace std;
const int F=1000;
struct s{
	int a,b;
};
bool cmp(s a,s b){
	return a.a>b.a;
}
s a[F];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[0].a;
	a[0].b=0;
	for(int i=1;i<n*m;i++){
		scanf("%d",&a[i]);
		a[i].b=i+1;
	}
	sort(a,a+n*m,cmp);
	int k=-1;
	for(int i=0;i<n*m;i++){
		if(a[i].b==0)k=i;
	}
	k++;
	int kk=ceil(k/(n+0.0));
	cout<<ceil(k/(n+0.0))<<" ";
	int q=k-(kk-1)*n;
	if(kk%2==0){
		cout<<n-q+1;
	}
	else cout<<q;
	cout<<"\n";
}/*
98 100 99 97*/