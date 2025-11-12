#include <iostream>
using namespace std;
int n,m,k;
struct old{
	int a,b,c;
}cityroad[1000010];
struct New{
	int a,b,c,d,e;
}country[10];
int oldcity[10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>cityroad[i].a
		   >>cityroad[i].b
		   >>cityroad[i].c;
	}for(int i=0;i<k;i++){
		cin>>country[i].a
		   >>country[i].b
		   >>country[i].c
		   >>country[i].d
		   >>country[i].e;
	}
}
