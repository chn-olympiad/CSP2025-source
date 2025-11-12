#include<bits/stdc++.h>
using namespace std;
long long n,k1,a1[1000000],bj[1000000];
struct node{
	long long s,xb;
}a[1000000];
bool cmp(node l,node r){
	if(l.s!=r.s){
		return l.s<r.s;
		
	}
	return l.xb<r.xb;
}
long long find(long long b){
	long long l=-1,r=n;
	while(l+1<r){
		long long mid=(l+r)/2;
		if(a[mid].s<=b){
			l=mid;
		}else{
			r=mid;
		}
		
	}
	return l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k1;
	for(long long i=1;i<=n;i++){
		cin>>a1[i];
		a1[i]=a1[i]^a1[i-1];
		a[i].s=a1[i];
		a[i].xb=i;
	}
	sort(a+1,a+1+n,cmp);
	long long ans=0;
	for(long long i=1;i<=n;i++){
		if(bj[i]==1){
			continue;
		}
		long long b=a1[i]^k1;
		long long fb=find(b);
		while(a[fb].s==b){
			if(a[fb].xb==i){
				fb++;
				continue;
			}
			if(bj[a[fb].xb+1]==0){
				bj[a[fb].xb+1]=1;
				bj[i]=1;
				ans++;
				break;
			}else{
				fb++;
			}
		}
	}
	cout<<ans;
	return 0;
}
