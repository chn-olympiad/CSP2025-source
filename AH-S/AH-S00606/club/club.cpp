#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][5],f[N];
int like[5];
struct node{
	int val,id,to;
}cha[N];
void read(){
	like[1]=like[2]=like[3]=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		f[i]=1;
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(a[i][j]>a[i][f[i]])f[i]=j;
		}
		like[f[i]]++;
	}
}
bool cmp(node x,node y){
	return x.val<y.val;
}
void answer(int by,int num,int ans){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(f[i]==by){
			cha[++cnt].id=i;
			cha[cnt].val=INT_MAX;
			for(int j=1;j<=3;j++){
				if(j!=by){
					int co=a[i][by]-a[i][j];
					if(co<cha[cnt].val){
						cha[cnt].val=co;
						cha[cnt].to=j;
					}
				}
			}
		}
	}
	sort(cha+1,cha+cnt+1,cmp);
	num-=n/2;
	for(int i=1;i<=num;i++){
		ans-=cha[i].val;
	}
	cout<<ans<<"\n";
}
void solve(){
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i][f[i]];
	}
	if(like[1]<=n/2&&like[2]<=n/2&&like[3]<=n/2){
		cout<<ans<<"\n";
		return;
	}
	else{
		if(like[1]>n/2)answer(1,like[1],ans);
		if(like[2]>n/2)answer(2,like[2],ans);
		if(like[3]>n/2)answer(3,like[3],ans);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		read();
		solve();
	}
	return 0;
}
