#include<bits/stdc++.h>
using namespace std;
struct V{
	int pos,c;
}a[101];
bool cmp(V x,V y){
	return x.c>y.c;
}
int n,m,k;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].c;
		a[i].pos=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].pos==1){
			k=i;
			break;
		}
	}
	int lll=(k-1)/n+1;
	cout<<lll<<" ";
	if(lll%2==1){
		cout<<k-(lll-1)*n;
	}
	else{
		cout<<n+1-k+(lll-1)*n;
	}
	return 0;
}