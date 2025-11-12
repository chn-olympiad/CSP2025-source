#include <bits/stdc++.h>
using namespace std;
int n,m;
struct nod{
	int num;
	int id;
}a[110];
bool cmp(nod p,nod q){
	return p.num>q.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			int l=i/n;
			if(i%n!=0) l++;
			int h=1;
			if(l%2){
				h=i%n;
			}else{
				h=n-i%n+1;
			}
			cout<<l<<" "<<h<<endl;
			break;
		}
	}
	return 0;
}
