#include<bits/stdc++.h>
using namespace std;
int seat[20][20];
struct node {
	int data;
	int index;
} a[200];
bool cmp(node x,node y) {
	return x.data>y.data;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int want;
	cin>>n>>m;
	int l=n*m;
	for(int i=1; i<=l; i++) {
		cin>>a[i].data;
		a[i].index=i;
	}
	want=a[1].data;
	sort(a+1,a+1+l,cmp);
	int p=1;
	int x=1,y=1;
	while(p<l+1) {
		if(y%2==0&&x==0)y++,x=1;
		else if(y%2!=0&&x==n+1)y++,x=n;
		else ;
		if(a[p].data==want&&a[p].index==1) {
			cout<<y<<" "<<x;
			return 0;
		}
		p++;
		if(y%2==0)x--;
		else x++;

	}

}
