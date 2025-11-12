#include<bits/stdc++.h>
using namespace std;
bool tong[500005];
struct m{
	int my,p;
};
m p1[500005],p2[500005],p3[500005];
bool cmp(m x,m y){
	if(x.my==y.my){
		return x.p<y.p;
	}
	return x.my>y.my;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p1[i].my>>p2[i].my>>p3[i].my;
			p1[i].p=p2[i].p=p3[i].p=i;
			tong[i]=0;
		}
		sort(p1+1,p1+1+n,cmp);
		sort(p2+1,p2+1+n,cmp);
		sort(p3+1,p3+1+n,cmp);
		//for(int i=1;i<=n;i++){
		//	cout<<p1[i].my<<' '<<p2[i].my<<' '<<p3[i].my<<endl;
		//}
		int k=0,c1=1,c2=1,c3=1,ans=0,v1=0,v2=0;
		while(k!=n){
			while(tong[p1[c1].p]){
				c1++;
			}
			while(tong[p2[c2].p]){
				c2++;
			}
			while(tong[p3[c3].p]){
				c3++;
			}
			if(p1[c1].my>=p2[c2].my&&p1[c1].my>=p3[c3].my&&v1<n/2){
				ans+=p1[c1].my;
				tong[p1[c1++].p]=1;
				k++;
				v1++;
				//cout<<1<<endl;
			}
			else if(p2[c2].my>=p1[c1].my&&p2[c2].my>=p3[c3].my&&v2<n/2){
				ans+=p2[c2].my;
				tong[p2[c2++].p]=1;
				k++;
				v2++;
				//cout<<2<<endl;
			}
			else{
				ans+=p3[c3].my;
				tong[p3[c3++].p]=1;
				k++;
				//cout<<3<<endl;
			}
			//cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
