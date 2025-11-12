#include <bits/stdc++.h>
using namespace std;
struct pepo{
	int a;
	int b;
	int c;
};
long long n;
long long x,js=0,a1=0,b1=0,c1=0;
pepo co[100005];
void DFS(long long cw,long long max1){
	if(cw>x){
		js=max(js,max1);
		return;
	}
	if(a1<x/2){
		a1++;
		DFS(cw+1,max1+co[cw].a);
		a1--;
	}
	if(b1<x/2){
		b1++;
		DFS(cw+1,max1+co[cw].b);
		b1--;
	}
	if(c1<x/2){
		c1++;
		DFS(cw+1,max1+co[cw].c);
		c1--;
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		js=0,a1=0,b1=0,c1=0;
		cin>>x;
		for(int o=1;o<=x;o++){
			cin>>co[o].a>>co[o].b>>co[o].c;
		}
		DFS(1,0);
		cout<<js<<endl;
	}
	return 0;
}

