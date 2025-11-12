#include<bits/stdc++.h>
using namespace std;
struct NODE{
	int s,id;
};
bool cmp(NODE a,NODE b){
	return a.s>b.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,h;
	cin>>n>>m;
	int nm=n*m;
	vector<NODE> a(nm);
	for(int i=0;i<nm;i++){
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<nm;i++) if(!a[i].id) h=i+1;
	int c=(h-1)/n+1,mo=h%n;
	if(!mo) mo=n;
	int r=c%2?mo:n-mo+1;
	cout<<c<<" "<<r;
	return 0;
}
