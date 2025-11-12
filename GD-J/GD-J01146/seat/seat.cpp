#include<bits/stdc++.h>
using namespace std;
struct stu{
	int fen;
	bool is=0;
};
bool cmp(stu a,stu b){
	return a.fen>b.fen;
}
int n,m;
double index;
stu a[201],r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].fen;
	r.fen=a[1].fen;	a[1].is=true;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].fen==r.fen&&a[i].is){
			index=i;
			break;
		}
	}
	if(!ceil(index/n)%2) cout<<ceil(index/n)<<" "<<n-int(index)%n-1;
	else cout<<ceil(index/n)<<" "<<int(index)%n;
	return 0;
}
