#include<bits/stdc++.h>
using namespace std;
int t,n;
bool jr[100005];
struct abab{
	int z,r;
}a[1005],b[1005],c[1005];
bool cmp(abab a,abab b){
	return a.z>b.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			scanf("%d%d%d",&a[j].z,&b[j].z,&c[j].z);
			a[j].r=b[j].r=c[j].r=j;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		int h=n,a1=1,b1=1,c1=1,ans=0;
		int a2=0,b2=0,c2=0;
		for(int i=1;i<=n;i++)
		{
			jr[i]=0;
		}
		while(h--){
			if(!jr[a[a1].r]&&a[a1].z>=b[b1].z&&a[a1].z>=c[c1].z&&a2<n/2){
				ans+=a[a1].z;
				jr[a[a1].r]=1;
				a2++;a1++;
			}
			else if(!jr[b[b1].r]&&a[a1].z<=b[b1].z&&b[b1].z>=c[c1].z&&b2<n/2){
				ans+=b[b1].z;
				jr[b[b1].r]=1;
				b2++;b1++;
			}
			else{
				if(!jr[c[c1].r]&&c2<n/2){
					ans+=c[c1].z;
					jr[c[c1].r]=1;
					c2++;c1++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
