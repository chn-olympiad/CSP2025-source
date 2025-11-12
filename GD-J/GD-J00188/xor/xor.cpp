#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
struct aa{
	int x,y;
};
aa b[500005];
bool cmp(aa x,aa y){
	return x.y<y.y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int d=0,c,e;
	for(int i=1;i<=n;i++){
		e=i;
		c=a[e];
		while(e<=n&&c!=k){
			e++;
			c^=a[e];
		}
		if(c==k){
			b[d++]={i,e};
		}
	}
	sort(b,b+d,cmp);
	c=0,e=0;
	for(int i=0;i<d;i++){
		if(b[i].x>c){
			e++;
			c=b[i].y;
		}
	}
	cout<<e;
	return 0;
}
