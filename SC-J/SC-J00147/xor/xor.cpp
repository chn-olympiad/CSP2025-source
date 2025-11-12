#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[50005],ans=0,lb[5005][3],qj=1,q;
ll l,r;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	l=1;
	lb[0][2]=1;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]==k){
			if(l!=i){
				lb[qj][0]=l;
				lb[qj][1]=i-1;
				lb[qj][2]=qj+1;
				qj++;
			}
			l=i+1;
			ans++;
		}
	}if(l!=n+1){
		lb[qj][0]=l;
		lb[qj][1]=n;
		lb[qj][2]=qj+1;
		qj++;
	}
	q=qj;
	ll len=2;
	ll pl,pr;
	ll xo=0;
	while(lb[0][2]!=q){
		pl=0;
		pr=lb[0][2];
		while(pr!=q){
			if(lb[pr][1]-lb[pr][0]+1<len){
				lb[pl][2]=lb[pr][2];
				pr=lb[pr][2];
				continue;
			}
			xo=0;
			for(int l=lb[pr][0];l<=lb[pr][0]+len-1;l++){
				xo^=a[l];
			}
			if(xo==k){
				ans++;
				if(lb[pr][1]-lb[pr][0]+1==len){
					lb[pl][2]=lb[pr][2];
					pr=lb[pr][2];
					continue;
				}else{
					lb[pl][2]=qj;
					lb[qj][0]=lb[pr][0]+len;
					lb[qj][1]=lb[pr][1];
					lb[qj][2]=lb[pr][2];
					pr=qj;
					qj++;
					continue;
				}
			}
			for(int l=lb[pr][0];l+len<=lb[pr][1];l++){
				//cout<<"K3";
				xo^=a[l];
				xo=l+len;
				if(xo==k){
					ans++;
					if(l+len==lb[pr][1]){
						lb[pl][2]=qj;
						lb[qj][0]=lb[pr][0];
						lb[qj][1]=lb[pr][1]-len;
						lb[qj][2]=lb[pr][2];
						pr=qj;
						qj++;
						break;
					}else{
						lb[pl][2]=qj;
						lb[qj][0]=lb[pr][0];
						lb[qj][1]=l;
						lb[qj][2]=qj+1;
						qj++;
						lb[qj][0]=l+len+1;
						lb[qj][1]=lb[pr][1];
						lb[qj][2]=lb[pr][2];
						qj++;
						continue;
					}
				}
			}
			pl=pr;
			pr=lb[pr][2];
		}
		len++;
	}
	cout<<ans;
	return 0;
}
