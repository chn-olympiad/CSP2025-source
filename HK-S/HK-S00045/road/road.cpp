#include<bits/stdc++.h>
using namespace std;
long long n,m,k,cut=0,ans=0;
long long int t[10000000]={};
struct road{
	int l;
	int e;
	int p;
}r[10000000];
bool cmp(road x,road y){
	return x.p>y.p;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>r[i].l>>r[i].e>>r[i].p;
		t[r[i].l]++;
		t[r[i].e]++;
		ans+=r[i].p;
	}
	sort(r,r+m,cmp);
	for(int i=0;i<m;i++){
		if(t[r[i].l]>1 && t[r[i].e]>1 && cut<(m-n+1)){
			ans-=r[i].p;
			t[r[i].l]--;
			t[r[i].e]--;
			cut++;
		}
	}
	if(k<=0) cout<<ans;
	else cout<<0;
	return 0;
}
