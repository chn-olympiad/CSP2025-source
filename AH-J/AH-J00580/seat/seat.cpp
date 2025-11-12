#include <bits/stdc++.h>
using namespace std;

int n,m;

struct node{
	int a,b;
} k[250];

bool cmp(node x,node y){
	return x.a>y.a;
}

int main(){
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	scanf ("%d %d",&n,&m);
	int l=n*m,f=1,dx=1,dy=1;
	for (int i=1;i<=l;i++){
		cin >> k[i].a; 
		k[i].b=i;
	}
	sort (k+1,k+l+1,cmp);
	for (int i=1;i<=l;i++){
			if (k[i].b==1) {
				cout << dx << " " << dy;
				break;
			}
			dy+=f;
			if (dy>n) f=-1,dx++,dy--;
			else if (dy<1) f=1,dx++,dy++;
	}
	return 0;
}
