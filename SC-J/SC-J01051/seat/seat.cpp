#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int u,num;
}a[N];
bool cmp(node x,node y){
	return x.num>y.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,mm;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].u=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i].u==1){
			mm=i;
			break;
		}
	int l=mm/n,nn=mm-l*n;
	if(mm%n!=0){
		if((l+1)%2==1) cout<<l+1<<' '<<nn;
		else cout<<l+1<<' '<<n-nn+1;		
	}
	else
		cout<<l<<' '<<(l%2==0?1:n);
	return 0;
} 