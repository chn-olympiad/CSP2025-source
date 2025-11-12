#include <bits/stdc++.h>
using namespace std;

long long t;
struct Thing{
	long long a,b,c,maxs,max2,mins,maxi,max2i,mini;
}thing[100010];
bool cmp(Thing x,Thing y){
	if(x.maxs!=y.maxs){
		return x.maxs>y.maxs;
	}
	if(x.max2!=y.max2){
		return x.max2>y.max2;
	}
	return x.mins>y.mins;
}
void work(long long &n,Thing thing[]){
	long long ans=0,p[10]={0};
	for(long long i=1;i<=n;i++){
		if(p[thing[i].maxi]+1<=n/2){
			ans+=thing[i].maxs;
			p[thing[i].maxi]++;
		}else if(p[thing[i].max2i]+1<=n/2){
			ans+=thing[i].max2;
			p[thing[i].max2i]++;
		}else{
			ans+=thing[i].mins;
			p[thing[i].mini]++;
		}
	}
	cout << ans << "\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		long long n;
		bool f1=true;
		cin >> n;
		for(long long i=1;i<=n;i++){
			cin >> thing[i].a >> thing[i].b >> thing[i].c;
			thing[i].maxs=thing[i].a,thing[i].max2=thing[i].b,thing[i].mins=thing[i].c;
			thing[i].maxi=1,thing[i].max2i=2,thing[i].mini=3;
			if(thing[i].maxs<thing[i].max2){
				swap(thing[i].maxs,thing[i].max2),swap(thing[i].maxi,thing[i].max2i);
			}
			if(thing[i].maxs<thing[i].mins){
				swap(thing[i].maxs,thing[i].mins),swap(thing[i].maxi,thing[i].mini);
			}
			if(thing[i].max2<thing[i].mins){
				swap(thing[i].max2,thing[i].mins),swap(thing[i].max2i,thing[i].mini);
			}
			if(thing[i].b>0 || thing[i].c>0){
				f1=false;
			}
		}
		stable_sort(thing+1,thing+n+1,cmp);
		if(f1){
			long long ans=0;
			for(long long i=1;i<=n/2;i++){
				ans+=thing[i].a;
			}
			cout << ans << "\n";
			continue;
		}
		work(n,thing);
	}
	return 0;
}
