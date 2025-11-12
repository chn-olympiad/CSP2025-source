#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int t,n;
long long ans;
struct nows{
	int num,lst[maxn/2];
}dep[5];
struct sta{
	int num,di;
};
struct peo{
	int p;
	sta nums[5];
}ps[maxn];
int people[maxn];
bool cmp1(sta a,sta b){
	return a.num>b.num;
}
bool cmp2(peo a,peo b){
	int i=1;
	for(;a.nums[i].num==b.nums[i].num&&i<=3;i++);
	return a.nums[i].num>b.nums[i].num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		ans=0;
		memset(people,0,sizeof(people));
		memset(dep,0,sizeof(dep));
		for(int j=1;j<=n;j++){
			ps[j].p=j;
			for(int k=1;k<=3;k++){
				cin>>ps[j].nums[k].num;
				ps[j].nums[k].di=k;
			}
		}
		for(int j=1;j<=n;j++)
			sort(ps[j].nums+1,ps[j].nums+4,cmp1);
		sort(ps+1,ps+n+1,cmp2);
		for(int j=1;j<=n;j++){
			if(!people[ps[j].p]){
				if(dep[ps[j].nums[1].di].num<n/2){
					ans+=ps[j].nums[1].num;
					dep[ps[j].nums[1].di].num++;
					int num=dep[ps[j].nums[1].di].num;
					dep[ps[j].nums[1].di].lst[num]=j;
					int last1=dep[ps[j].nums[1].di].lst[num-1],now=num-1;
					while(ps[last1].nums[1].num-ps[last1].nums[2].num<ps[j].nums[1].num-ps[j].nums[2].num&&now>=1){
						swap(dep[ps[j].nums[1].di].lst[now],dep[ps[j].nums[1].di].lst[now+1]);
						now--;
						last1=dep[ps[j].nums[1].di].lst[now];
						j=dep[ps[j].nums[1].di].lst[now+1];
					}
				}
				else{
					int num=dep[ps[j].nums[1].di].num;
					int last1=dep[ps[j].nums[1].di].lst[num];
					if(ps[last1].nums[1].num+ps[j].nums[2].num<ps[last1].nums[2].num+ps[j].nums[1].num){
						ans+=ps[j].nums[1].num-ps[last1].nums[1].num+ps[last1].nums[2].num;
						dep[ps[last1].nums[2].di].num++;
						dep[ps[j].nums[1].di].lst[num]=j;
						last1=dep[ps[j].nums[1].di].lst[num-1];
						int now=num-1;
						while(ps[last1].nums[1].num-ps[last1].nums[2].num<ps[j].nums[1].num-ps[j].nums[2].num&&now>=1){
							swap(dep[ps[j].nums[1].di].lst[now],dep[ps[j].nums[1].di].lst[now+1]);
							now--;
							last1=dep[ps[j].nums[1].di].lst[now];
							j=dep[ps[j].nums[1].di].lst[now+1];
						}
					}
					else{
						ans+=ps[j].nums[2].num;
						dep[ps[j].nums[2].di].num++;
					}
				}
				people[ps[j].p]=1;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
