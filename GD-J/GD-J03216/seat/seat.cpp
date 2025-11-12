#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,len,c,r;
struct abc{
	int mark,ip;
}a[N];
bool cmp(abc a,abc b){
	return a.mark>b.mark;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	len=n*m;
	for(int i=1;i<=len;i++){
		cin>>a[i].mark;
		a[i].ip=i;
	}
	sort(a+1,a+len+1,cmp);
	int x=0;
	for(int i=1;i<=len;i++){
		if(a[i].ip==1) x=i;
	}
	if(x%n!=0){
		c=x/n+1;
		int y=x%n;
		if(c%2!=0) r=y;
		else r=n-y+1;
	}
	else{
		c=x/n;
		if(c%2!=0) r=n;
		else r=1;
	}
	cout<<c<<" "<<r;
}
