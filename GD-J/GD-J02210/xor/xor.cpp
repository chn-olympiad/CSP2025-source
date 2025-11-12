#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,k,cnt,ans;
int a[N],s[N];
struct node{
	int l,r;
}qj[N*N];
bool cmp(node a,node b){
	if(a.r!=b.r) return a.r<b.r;
	else return a.l>b.l;
}
int main () {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
	    cin>>a[i];	
	}
	for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int res=s[j]^s[i-1];
			if(res==k){
			    qj[++cnt].l=i,qj[cnt].r=j; 	
			}
		}
	}
	sort(qj+1,qj+1+cnt,cmp);
	bool flag=1;
	int ll=0,i=1;
	while(flag){
		while(qj[i].l<=ll){
		   i++;
		   if(i>cnt){
		   	cout<<ans;
		   	return 0;
		   }	
		} 
		ans++;
		ll=qj[i].r;
	}
	return 0;
}
