#include <bits/stdc++.h>
using namespace std;
struct a{
	long long u;
	long long v;
	long long w;
}b[10000005];
bool cmp(a x,a y){
	return x.w < y.w;
}
long long n,m,k,num=0,p[1005],o=2;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n>>m>>k;
	for(int i=0;i < m;i++){
		cin >>b[i].u>>b[i].v>>b[i].w;
	}
	for(int i=0;i < n;i++){
		p[i]= 0;
	}
	sort(b,b+m,cmp);
	p[b[0].u] = 1;
	p[b[0].v] = 1;
	num += b[0].w;
	for(int i=1;i < m;i++){
		if(p[b[i].u] == 1){
			p[b[i].v] = 1;
			o++;
			num += b[i].w;
		}
		else if(p[b[i].v] == 1){
			p[b[i].u] = 1;
			o++;
			num += b[i].w;
		}
		if(o == n){
			cout <<num;
			return 0;
		}
	}
	return 0;
}
