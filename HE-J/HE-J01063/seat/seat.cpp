#include<bits/stdc++.h>
using namespace std;
int n,m,a[12][12],c,d;
struct abc{
	int h,l,s;
}b[144];
bool cmp(abc a,abc b){
	return a.s>b.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	d=1;
	for(int i=1;i<=n*m;i++){
		cin>>b[i].s;
	}
	c=b[1].s;
	sort(b+1,b+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==0){
			for(int i=n;i>=1;i--){
				b[d].h=i;
				b[d].l=j;
				if(b[d].s==c){
					cout<<b[d].l<<" "<<b[d].h;
				}
				d++;
			}
		}else{
			for(int i=1;i<=n;i++){
				b[d].h=i;
				b[d].l=j;
				if(b[d].s==c){
					cout<<b[d].l<<" "<<b[d].h;
				}
				d++;
			}
		}
	}
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/
