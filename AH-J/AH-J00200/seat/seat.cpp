#include<bits/stdc++.h>
using namespace std;
int n,m,sum,a[105],s,q,w;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++)
		cin>>a[i];
	s=a[1];
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++)
		if(a[i]==s)
			s=i;
	q=s/n+1;
	w=s%n;
	if(w==0){
		w=n;
		q=q-1;	
	}
	if(q%2==0)
		w=n-w+1;
	cout<<q<<" "<<w;
	return 0;
}
