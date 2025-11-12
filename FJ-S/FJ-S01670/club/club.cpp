#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][5],p,b1[100005],b2[100005],b3[100005],h1,h2,h3,ans;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t>0){
		t--;
		cin>>n;
		h1=h2=h3=0;
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
//			cin>>a[i][1]>>a[i][2]>>a[i][3];
			p=max(a[i][1],max(a[i][2],a[i][3]));
			ans+=p;
			if(p==a[i][1]){
				h1++;
				b1[h1]=max(a[i][2],a[i][3])-p;
			}else if(p==a[i][2]){
				h2++;
				b2[h2]=max(a[i][1],a[i][3])-p;
			}else if(p==a[i][3]){
				h3++;
				b3[h3]=max(a[i][1],a[i][2])-p;
			}
		}
		if(h1>n/2){
			sort(b1+1,b1+1+h1,cmp);
			for(int i=1;i<=h1-n/2;i++) ans+=b1[i];
		}else if(h2>n/2){
			sort(b2+1,b2+1+h2,cmp);
			for(int i=1;i<=h2-n/2;i++) ans+=b2[i];
		}else if(h3>n/2){
			sort(b3+1,b3+1+h3,cmp);
			for(int i=1;i<=h3-n/2;i++) ans+=b3[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
