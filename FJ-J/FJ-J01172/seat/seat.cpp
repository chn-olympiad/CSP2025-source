#include<bits/stdc++.h>
using namespace std;
int n,m,l;
struct cj{
	int id,f;
}a[110];
bool cmp(cj x,cj y){
	return x.f>y.f;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].f;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			l=0;
			if(i%n==0){
				cout<<i/n<<' ';
				l=i/n;
			}
			else{
				cout<<i/n+1<<' ';
				l=i/n+1;
			}
			if(l%2==1){
				cout<<(i-1)%n+1;
			}
			else{
				cout<<n-((i-1)%n+1)+1;
			}
			break;
		}
	}
	return 0;
}
