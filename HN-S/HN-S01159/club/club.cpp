#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,int>
const int N=1e5+10;
int T;
int a[N][4];
int fst[N],sec[N];
priority_queue<pr,vector<pr>,greater<pr> > q;
int ans,n;

int rd(){
	int x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=rd();
	while(T--){
		ans=0;
		n=rd();
		for(int i=1;i<=n;i++){
			a[i][1]=rd();
			a[i][2]=rd();
			a[i][3]=rd();
		}
		for(int i=1;i<=n;i++){
			int maxs=max(a[i][1],max(a[i][2],a[i][3]));
			if(maxs==a[i][1]){
				fst[i]=1;
				if(a[i][2]>a[i][3])sec[i]=2;
				else sec[i]=3;
			}
			else if(maxs==a[i][2]){
				fst[i]=2;
				if(a[i][1]>a[i][3])sec[i]=1;
				else sec[i]=3;
			}else if(maxs==a[i][3]){
				fst[i]=3;
				if(a[i][1]>a[i][2])sec[i]=1;
				else sec[i]=2;
			}
			//cout<<fst[i]<<' '<<sec[i]<<endl;
		}
		while(!q.empty())q.pop();
		int c1=0,c2=0,c3=0,p=0;
		for(int i=1;i<=n;i++){
			if(fst[i]==1)c1++;
			else if(fst[i]==2)c2++;
			else if(fst[i]==3)c3++;
		}
		int tmp=max(c1,max(c2,c3));
		if(tmp<=n/2){
			for(int i=1;i<=n;i++)
				ans+=a[i][fst[i]];
			printf("%lld\n",ans);
			continue;
		}
		if(tmp==c1)p=1;
		else if(tmp==c2)p=2;
		else if(tmp==c3)p=3;
		for(int i=1;i<=n;i++){
			if(fst[i]==p){
				if(q.size()<n/2){
					q.push({a[i][fst[i]]-a[i][sec[i]],i});
					ans+=a[i][fst[i]];
				}else{
					int t=q.top().second;
					if(a[i][fst[i]]-a[t][fst[t]]+a[t][sec[t]]>a[i][sec[i]]){
						ans+=a[i][fst[i]]-a[t][fst[t]]+a[t][sec[t]];
						q.pop();
						q.push({a[i][fst[i]]-a[i][sec[i]],i});
					}else ans+=a[i][sec[i]];
				}
			}else ans+=a[i][fst[i]];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
