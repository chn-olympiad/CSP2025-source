#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int t,n,g,h,w[3];
ll o;
bool ji[N];
struct A{
	int a,b;
}x[N],y[N],z[N];
bool cmp(A t,A y){
	return t.a>y.a; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		w[0]=w[1]=w[2]=o=0;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>y[i].a>>z[i].a;
			x[i].b=y[i].b=z[i].b=i;
		}
		sort(x+1,x+n+1,cmp);
		sort(y+1,y+n+1,cmp);
		sort(z+1,z+n+1,cmp);
		for(int i=1;i<=n;i++){
			g=h=0;
			if(!ji[x[i].b]&&w[0]<(n+1)>>1&&x[i].a>g) g=x[i].a,h=0;
			if(!ji[y[i].b]&&w[1]<(n+1)>>1&&y[i].a>g) g=y[i].a,h=1;
			if(!ji[z[i].b]&&w[2]<(n+1)>>1&&z[i].a>g) g=z[i].a,h=2;
			o+=g;
			if(h==0) ji[x[i].b]=1;
			else if(h==1) ji[y[i].b]=1;
			else ji[z[i].b]=1;
		}
		cout<<o<<'\n';
	}
	return 0;
}