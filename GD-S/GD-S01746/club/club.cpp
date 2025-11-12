#include <bits/stdc++.h>
using namespace std;
long long t,n,ans;
struct p{
	int num,id;
}a[100005],b[100005],c[10005];

bool cmp(p gd,p fd){
	return gd.num>fd.num;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].num>>b[i].num>>c[i].num;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		
		for(int i=n/2+1;i<=n;i++){
			a[i].num=0;
			b[i].num=0;
			c[i].num=0;
		}
		int maxn=0;
		for(int i=1;i<=n/2;i++){
			if(a[i].id==b[i].id){
				if(a[i].id==c[i].id){
					maxn = max(c[i].num,max(a[i].num,b[i].num));
					a[i].num=0;
					b[i].num=0;
					c[i].num=0;
					ans+=maxn;
				}
				else if(a[i].id==c[i].id){
					maxn =max(a[i].num,c[i].num);
					a[i].num=0;
					c[i].num=0;
					ans+=maxn;
				}
			}
			else if(b[i].id==c[i].id){
					maxn =max(b[i].num,c[i].num);
					b[i].num=0;
					c[i].num=0;
					ans+=maxn;
				}
		}
		for(int i=1;i<=n/2;i++){
			ans+=a[i].num;
			ans+=b[i].num;
			ans+=c[i].num;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
