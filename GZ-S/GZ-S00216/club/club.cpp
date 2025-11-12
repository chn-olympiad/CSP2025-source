//GZ-S00216 贵阳市花溪区同为京学附属实验学校 李嘉成 
#include <bits/stdc++.h>
using namespace std;
struct xs{
	long long a,b,c,maxn;
}md[100005];
long long cnt[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		bool f=0;
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>md[i].a>>md[i].b>>md[i].c;
			md[i].maxn=max(max(md[i].a,md[i].b),md[i].c);
			cnt[md[i].maxn]++;
			ans+=md[i].maxn;
		}
		for(int i=1;i<=200005;i++){
			if(cnt[i]<=(n/2)){
				cout<<ans<<endl;
				f=1;
				break;
			}
		}
		if(f==1) continue;
	}
	return 0;
}
