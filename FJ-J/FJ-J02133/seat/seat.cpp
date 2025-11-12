#include <bits/stdc++.h>
using namespace std;
const int N=15;
int n,m;

struct Seat{
	int num;
	int id;
} a[N*N];

bool cmp(Seat x,Seat y){
	return x.num>y.num;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	int len=n*m;
	for (int i=1;i<=len;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+1+len,cmp);
	
	int k=0;
	for (int i=1;i<=len;i++){
		if (a[i].id == 1){
			k=i;
			break;
		}
	}
	
	int r=ceil(k*1.0/n),s=k%n,c=0;
	if (!s)	s=n;
	if (r%2)	c=s;
	else	c=n-s+1;
	
	cout<<r<<" "<<c<<"\n";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
