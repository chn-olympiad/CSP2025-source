#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int NM=1e3*1e3+100;
long long n,m;
struct node{
	long long num;
	long long index;
}a[NM];
struct node2{
	int x,y;
}map[NM];
bool cmp(node a,node b){
	return a.num>b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].index=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int m_i=1;
	for(long long i=1;i<=m;i++){
		if(i%2!=0){
			for(long long j=1;j<=n;j++){
				map[m_i].x=j;
				map[m_i].y=i;
				m_i++;
			}
		}else {
			for(long long j=n;j>=1;j--){
				map[m_i].x=j;
				map[m_i].y=i;
				m_i++;
			}
		}
		
	}
	int t;
	for(long long i=1;i<=n*m;i++){
		if(a[i].index==1){
			t=i;
			break;
		}
	}
	cout<<map[t].y<<' '<<map[t].x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}