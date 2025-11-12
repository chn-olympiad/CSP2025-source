#include<bits/stdc++.h>
using namespace std;
int n,m;
struct stu{
	int sco;
	int indx;
} a[1005];
bool cmp(const stu &a,const stu &b){
	return a.sco>b.sco;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	int tal=n*m;
	for(int i=1;i<=tal;++i)
		cin>>a[i].sco,a[i].indx=i;
	stable_sort(a+1,a+tal+1,cmp);
	int x=0,y=1,p=1;
	for(int i=1;i<=tal;++i){
		x+=p;
		if(x>n||x<1){
			++y;
			x-=p;
			p=-p;
		}
		if(a[i].indx==1){
			cout<<y<<' '<<x;
			return 0;
		}
	}
	return 0;
}
