#include<bits/stdc++.h>
using namespace std;
int n,m,r,c,stu,idx,a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	stu=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==stu){
			idx=i;
			break;
		}
	}
	r=(idx+n-1)/n;
	if(r%2){
		c=idx%n;
		if(c==0) c=n;
	}
	else{
		c=idx%n;
		if(c==0) c=n;
		c=n-c+1;
	}
	cout<<r<<" "<<c;
	return 0;
}
