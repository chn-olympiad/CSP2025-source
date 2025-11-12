 #include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1001000],l,i,j,n,m,x,k,xo[1001000],t,ans;
struct tt{
	ll l,r;
}s[1001000],q;
bool cmp(tt a,tt b){
	if(a.l==b.l) return a.r<b.r;
	return a.l<b.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>a[i];
		xo[i]=xo[i-1]^a[i];
	} 
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			if((xo[i]^xo[j-1])==k){
				t++;
				s[t].l=j;
				s[t].r=i;
			}
		}
	}
	sort(s+1,s+1+t,cmp);
	for(i=1;i<=t;i++){
		if(i==1){
			q=s[i],ans++;
		}
		else{
			if(s[i].r<q.r){
				q=s[i];
			}
			else if(s[i].l>q.r){
				q=s[i];
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
