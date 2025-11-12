#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m,xm;
struct stu{
	int id;
	int gr;
}a[110];
bool cmp(stu x,stu y){
	return x.gr>y.gr;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].gr;
	}
	a[1].id=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i].id==1){
			xm=i;
			break;
		}
	}
//	cout<<xm<<'\n';
	int b=((xm-1)/n)+1,c=0;
	if(b%2==1){
		c=(xm-1)%n+1;
	}
	else c=n-((xm-1)%n+1)+1;
	cout<<b<<' '<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
