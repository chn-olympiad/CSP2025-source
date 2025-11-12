#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
int a[100005];
struct jh2 {
	int a[10005];
};
int yh(int f,int e) {
	int sum;
	sum=a[f];
	for(int i=f+1; i<=e; i++)sum+=a[i];
	return sum;
}
int su=0;
void dt(int where,int hh,int hm,int fa,int la) {
	cout<<where<<" "<<hh<<" "<<hm<<" "<<fa<<" "<<la<<endl;
	if(hm>=3&&hh>2*la)su=max(su,fa);
	if(where>n)return;
	dt(where+1,hh+a[where],hm+1,fa+1,a[where]);
	dt(where+1,hh,hm,fa,la);
}
int main() {
	freopen("polygan.in","r",stdin);
	freopen("polygan.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i];
	dt(1,0,0,0,0);
	cout<<su;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
