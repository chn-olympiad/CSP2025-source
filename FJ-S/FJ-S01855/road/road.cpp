#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10005][10005];
long long sum=0;
struct aaa{
	int c,a[10005];
}b[15],l;
bool bbb(aaa k1,aaa k2){
	if(k1.c<k2.c) return k1.c<k2.c;
	else return k1.c>k2.c;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int a1,a2,a3;
	for(int i=1;i<=m;i++){
		cin>>a1>>a2>>a3;
		a[a1][a2]=a3;
	}
	l.c=INT_MAX;
	for(int i=1;i<=k;i++){
		cin>>b[i].c;
		if(l.c>b[i].c) l=b[i];
		for(int j=1;j<=n;j++){
			cin>>b[i].a[j];
		}
	}
	sum+=l.c;
	for(int i=1;i<=n;i++) sum+=l.a[i];
	cout<<sum<<endl;
	return 0;
}
