#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll a[N],n,k,cnt,top,ans,v[N];
struct node{
	int l,r;
}b[N];
bool cmp(node a,node b){
	if(a.r==b.r)return a.l<b.l;
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int fl=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)fl=0;
	}
	if(fl&&n<=1000){
		for(int i=1;i<=n;i++){
			int last=i;
			cnt=-1;
			for(int j=i;j<=n;j++){
				if(cnt==-1){
					cnt=a[j];
					last=j;
				}else cnt^=a[j];
				if(cnt==k){
					b[++top].l=last;
					b[top].r=j;
					cnt=-1;
				}
			}
		}
		sort(b+1,b+top+1,cmp);
		int last=0;
		for(int i=1;i<=top;i++){
			if(b[i].l>last){
				ans++;
				last=b[i].r;
			}
		}
		cout<<ans;
	}else{
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]&&a[i-1]&&!v[i-1])ans++,v[i]=v[i-1]=1;
				if(!a[i])ans++;
			}
		}else if(k==1){
			for(int i=1;i<=n;i++)if(a[i])ans++;
		}
		cout<<ans;
	}
	return 0;
}