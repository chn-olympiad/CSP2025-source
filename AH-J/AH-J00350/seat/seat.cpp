#include<bits/stdc++.h>
using namespace std;
long long n,m,idx,c,r,R;
struct node{
	long long score;
}a[1010];
bool cmp(node x,node y){
	return x.score>y.score;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].score;
		R=a[1].score;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].score==R){
			idx=i;
		}
	}
	if(idx<=n){
		cout<<1<<" "<<idx;
		return 0;
	}
	long long AC=floor(idx/n);
	long long tops=AC*n;
	long long AK=idx-tops;
	c=AC+1;
	if(AC%2==0){
		r=AK;
	}
	else{
		r=m-AK+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
