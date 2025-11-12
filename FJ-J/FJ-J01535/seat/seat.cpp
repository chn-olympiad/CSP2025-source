#include<bits/stdc++.h>
using namespace std;
int n,m,b=1,c=1;
struct kk{
	int a,b,c,d;
}a[1001];
bool aca(kk a,kk b){
	return a.a>b.a;
}
bool ca(kk a,kk b){
	return a.d<b.d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].a;
		a[i].d=i;
	}
	sort(a+1,a+1+n*m,aca);
	for(int i=1;i<=n*m;i++){
		a[i].b=b;
		a[i].c=c;
		if(b%2==1&&c!=n)c++;
		else if(b%2==0&&c!=1)c--;
		else if(b%2==1&&c==n)b++;
		else if(b%2==0&&c==1)b++;
	}
	sort(a+1,a+1+n*m,ca);
	cout<<a[1].b<<" "<<a[1].c;
	return 0;
}
