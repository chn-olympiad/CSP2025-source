#include<bits/stdc++.h>
using namespace std;
int n,k,m;
int a[600000];
struct re{
	int l;
	int r;
}p[600000];
bool cmp(re x,re y){
	return x.r<y.r||x.r==y.r&&x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t=a[i];
		bool o=0;
		for(int j=i+1;j<=n;j++){
			if(t==k){
				m++;
				p[m].l=i;
				p[m].r=j-1;
				o=1;
			}
			t=t^a[j];
		}
		if(o==0&&t==k){
			m++;
			p[m].l=i;
			p[m].r=n;
		}
	}
	
	sort(p+1,p+m+1,cmp);
	int rr=p[1].r;
	int ans=1;
	for(int i=2;i<=m;i++){
		if(p[i].l>rr){
			ans++;
			rr=p[i].r;
		}
	}
	cout<<ans;
	return 0;
}
