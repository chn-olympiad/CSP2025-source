#include<bits/stdc++.h>
using namespace std;
long long a[200005][5],s[8],p[5];
struct note{
	int ts,fl[5];
}f[200005];
int cmp(note x,note y){
	return x.ts<y.ts;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,ans=0;
	cin>>t;
	while(t--){
		cin>>n;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=3;j++){
				cin>>a[i][j];
			}
			ans+=max(max(a[i][1],a[i][2]),a[i][3]);
			if(a[i][1]==max(max(a[i][1],a[i][2]),a[i][3])){
				s[1]++;
				f[i].fl[1]=1;
			}
			if(a[i][2]==max(max(a[i][1],a[i][2]),a[i][3])){
				s[2]++;
				f[i].fl[2]=1;
			}
			if(a[i][3]==max(max(a[i][1],a[i][2]),a[i][3])){
				s[3]++;
				f[i].fl[3]=1;
			}
			f[i].ts=max(max(a[i][1],a[i][2]),a[i][3])-(a[i][1]+a[i][2]+a[i][3]-max(max(a[i][1],a[i][2]),a[i][3])-min(min(a[i][1],a[i][2]),a[i][3]));
		}
		sort(f+1,f+n+1,cmp);
		int N=s[1]+s[2]+s[3];
		for(int i=1;i<=N-n;i++){
			if(s[1]==max(s[1],max(s[2],s[3]))){
				s[1]--;
				f[i].fl[1]=0;
			}
			else if(s[2]==max(s[1],max(s[2],s[3]))){
				s[2]--;
				f[i].fl[2]=0;
			}
			else if(s[3]==max(s[1],max(s[2],s[3]))){
				s[3]--;
				f[i].fl[3]=0;
			}
		}
		int id;
		if(max(max(s[1],s[2]),s[3])==s[1]){
			id=1;
		}
		if(max(max(s[1],s[2]),s[3])==s[2]){
			id=2;
		}
		if(max(max(s[1],s[2]),s[3])==s[3]){
			id=3;
		}
		int j=1;
		for(long long i=1;i<=max(max(s[1],s[2]),s[3])-n/2;i++){
			while(f[j].fl[id]==0){
				j++;
			}
			ans-=f[j].ts;
			j++;
		} 
		cout<<ans<<endl;
		for(long long i=1;i<=n;i++){
			a[i][1]=a[i][2]=a[i][3]=f[i].ts=f[i].fl[1]=f[i].fl[2]=f[i].fl[3]=0;
		}
		s[1]=s[2]=s[3]=0;
		ans=0;
	} 
 	return 0;
}
