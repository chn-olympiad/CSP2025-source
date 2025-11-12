#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int val;
	bool flag=0;
}
a[10005];
int n,m;
bool cmp(node x,node y){
	return x.val>y.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	a[1].flag=1;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].val;
	}
	sort(a+1,a+n*m+1,cmp);
	int l=1,r=1,now=1;
	while(a[now].flag==0){
		if(r%2==1){
			l++;
			if(l>n){
				l=n;
				r++;
			}
		}else{
			l--;
			if(l<1){
				l=1;
				r++;
			}
		}
		now++;
	}
	cout<<r<<" "<<l;//RP++
	return 0;
}
