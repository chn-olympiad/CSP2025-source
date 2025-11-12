#include <bits/stdc++.h>
using namespace std;
int n,m,k,s[10005],a[10005],o,p,q,x=1,sum,st[1000005];
bool b[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(a,1e4+5,sizeof(a));
	memset(st,0,sizeof(s));
	for(int i=1;i<=m;i++){
		cin>>o>>p>>q;
		a[o]=min(a[o],q),a[p]=min(a[p],q);
		st[q]++;
	}
	int k=1;
	for(int i=1;i<=n;i++){
		if(a[i]<1e4+5){
			s[k]=a[i];
			k++;
		}
	}
//	sort(a+1,a+k+1);
	for(int i=1;i<=k;i++){
		if(s[i]!=s[i-1]){
			sum+=s[i];
		}
		else if(b[s[i]]==0){
			sum+=st[s[i]]*s[i]-s[i];
			b[s[i]]=1;
		}
	}
	cout<<sum;
	return 0;
}

