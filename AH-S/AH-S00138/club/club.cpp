#include <bits/stdc++.h>
using namespace std;
const int MA=50+5,MAXN=1e5+5;
struct L{
	int v1,v2,v3;
};
bool cmp1(L a,L b){
	return max(a.v2,a.v3)-a.v1<max(b.v2,b.v3)-b.v1;
}
bool cmp2(L a,L b){
	return max(a.v1,a.v3)-a.v2<max(b.v1,b.v3)-b.v2;
}
bool cmp3(L a,L b){
	return max(a.v2,a.v1)-a.v3<max(b.v2,b.v1)-b.v3;
}
int n;
L a[MAXN],b[MAXN],c[MAXN];
int cn1,cn2,cn3,sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		sum=cn1=cn2=cn3=0;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			if(x>=y&&x>=z){
				a[++cn1]={x,y,z};sum+=x;
			}
			else if(y>=x&&y>=z){
				b[++cn2]={x,y,z};sum+=y;
			}
			else{
				c[++cn3]={x,y,z};sum+=z;
			}
		}
		sort(a+1,a+1+cn1,cmp1);
		sort(b+1,b+1+cn2,cmp2);
		sort(c+1,c+1+cn3,cmp3);
		if(cn1>n/2){
			while(cn1>n/2){
				sum=sum-a[cn1].v1+max(a[cn1].v2,a[cn1].v3);
				cn1--;
			}
		}
		if(cn2>n/2){
			while(cn2>n/2){
				sum=sum-b[cn2].v2+max(b[cn2].v1,b[cn2].v3);
				cn2--;
			}
		}
		if(cn3>n/2){
			while(cn3>n/2){
				sum=sum-c[cn3].v3+max(c[cn3].v1,c[cn3].v2);
				cn3--;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
