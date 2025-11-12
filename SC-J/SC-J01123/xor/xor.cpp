#include<bits/stdc++.h>
using namespace std;
int n,k,a[200010],top=0,u=0,v=0;
struct node{
	int l,r;
}x[200010],m[200010];
bool cmp(node x,node y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int s=0;
			for(int e=i;e<=j;e++){
				s^=a[e];
			}
			if(s==k){
				x[++top].l=i;
				x[top].r=j;
			}
		}
	}
	sort(x+1,x+top+1,cmp);
	for(int i=1;i<=top;i++){
		int bj=0;
		for(int j=1;j<=u;j++){
			if(m[j].l<=x[i].l&&m[j].r>=x[i].l||m[j].l>=x[i].l&&m[j].r<=x[i].r){
				bj=1;
				break;
			}
		}
		if(bj==0){
			m[++u].l=x[i].l;
			m[u].r=x[i].r;
			v++;
		}
	}
	cout<<v;
	return 0;
}
/*
4 2
2 1 0 3

4 3
2 1 0 3
1 2
1 3
3 4
4 4

4 0
2 1 0 3
3 3
1 4

100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1


long long
暴力区间 ^[^-^-^-^-^-^-^
*/