#include <bits/stdc++.h>
using namespace std;
int n,m,c=1,r=0;
struct node{
	int a;
	bool f;
}a[105];
bool cmp(node x,node y){
	return x.a>y.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;++i){
		scanf("%d",&a[i].a);
	}
	a[1].f=true;
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;++i){
//		cout<<a[i].a<<" ";
//	}
	bool f=true;
	for(int i=1;i<=n*m;++i){
		if(f){
			r++;
			if(r>m){
				f=false;
				r=m;
				c++;
//				cout<<"c,r:"<<c<<","<<r<<"\n";
			}
		}else{
			r--;
			if(r<1){
				f=true;
				r=1;
				c++;
			}
		}
		if(a[i].f){
			break;
		}
	}
	printf("%d %d",c,r);
	return 0;
}
