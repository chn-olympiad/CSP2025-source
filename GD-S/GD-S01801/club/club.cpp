#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,a[100005][4],maxn[100005][2],ans,s[4];
struct dd{
	ll num,cha;
}b[4][100005];
bool cmp(dd x,dd y){
	return x.cha>y.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(ll i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			maxn[i][0]=0,maxn[i][1]=0;
			for(ll j=1;j<=3;j++){//找最满意和次满意的部门 
				if(a[i][maxn[i][0]]<a[i][j])
				    maxn[i][1]=maxn[i][0],maxn[i][0]=j;
				else if(a[i][maxn[i][1]]<a[i][j])
				        maxn[i][1]=j;
			}
			ans+=a[i][maxn[i][1]];//加上次满意的值 
			for(ll j=1;j<=3;j++){
				b[j][i].cha=a[i][j]-a[i][maxn[i][1]];//减去次满意的值 
				b[j][i].num=i;
			}
		}
		for(ll i=1;i<=3;i++){
			sort(b[i]+1,b[i]+1+n,cmp);
			s[i]=0;
			int j=1;
			for(ll j=1;j<=n;j++)
			    if(maxn[b[i][j].num][0]==i&&s[i]<n/2){
			    	ans+=b[i][j].cha;
			    	s[i]++;
				}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
