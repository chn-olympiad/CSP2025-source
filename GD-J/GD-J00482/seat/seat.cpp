#include<bits/stdc++.h>
using namespace std;
int n,m,a[555],z,b,c,d,e;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[z];
			z++;
		}
	}
	b=a[0];
	sort(a,a+z,cmp);
	for(int i=0;i<z;i++) if(a[i]==b) c=(i+1);
	d=c/m;
	e=c%m;
	if(c<m||e!=0) d++;
	if(d%2!=0) cout<<d<<" "<<m-e;
	if(e==0) e=5;
	if(d%2==0) cout<<d<<" "<<(m+1)-e;
	return 0;
}
