#include<bits/stdc++.h>
using namespace std;
struct node{
	int num;
	int indx;
} a[1005];
bool cmp(node a,node b){
	return a.num>b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n>>m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i].num;
		a[i].indx=i;
	}
	int s=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].indx==1){
			s=i;
			break;
		}
	}
	int b=(s%n==0?n:s%n),c=ceil(s*1.0/n);
	b=(c%2==0?n-b+1:b);
	cout << c <<' '<< b ;
}
