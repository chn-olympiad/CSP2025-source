#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y;
	cin>>x>>y;
	int a[x*y];
	for(int i=0;i<x*y;i++){
		cin>>a[i];
	}
	int n=a[0],m;
	sort(a,a+x*y,cmp);
	for(int i=0;i<x*y;i++){
		if(a[i]==n)m=i+1;
	}
	int ls1=ceil(m*1.0/(x*2)),ls2=m%(x*2);
	if(ls2>0&&ls2<x+1)cout<<ls1*2-1<<" "<<ls2;
	else if(ls2==0)cout<<ls1*2<<" "<<1;
	else cout<<ls1*2<<" "<<x-(ls2-x)+1;
	return 0;
} 
