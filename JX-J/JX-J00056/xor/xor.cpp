#include<bits/stdc++.h>
using namespace std;
int n,k,h,s,f,l,r,m;
int a[500005];
int d[500005];
pair<int,int>e[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		d[i]=d[i-1]^a[i];
		e[i]=make_pair(d[i],i);
	}
	sort(e+1,e+n+1);
	h=n;
	for(int i=n-1;i>=0;i--){
		if(a[i+1]==k){
			s++;
			h=i+1;
			continue;
		}
		f=d[i]^k;
		int l=1,r=n;
		while(l<=r){
			m=(l+r)/2;
			if(e[m].first>f){
				r=m-1;
			}
			else if(e[m].first==f&&e[m].second>=h){
				r=m-1;
			}
			else if(e[m].first<f){
				l=m+1;
			}
			else if(e[m].first==f&&e[m].second<=i){
				l=m+1;
			}
			else{
				s++;
				h=i+1;
				break;
			}
		}
	}
	printf("%d",s);
	return 0;
}
