#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100005
int t;
struct NODE{
	int mn,mid,mx;
	int mn_id,mid_id,mx_id;
};
struct NUM{
	int num,id;
};
NODE val[N];
int n;
bool cmp1(NUM x,NUM y){
	return x.num>y.num;
}
bool cmp(NODE x,NODE y){
	return x.mx-x.mid>y.mx-y.mid;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		int cnt[4]={-1,0,0,0};
		cin>>n;
		for(int i=1;i<=n;i++){
			NUM a[4];
			for(int j=1;j<=3;j++){
				cin>>a[j].num;
				a[j].id=j;
			}
			if(a[1].num<a[2].num) swap(a[1],a[2]);
			if(a[2].num<a[3].num) swap(a[2],a[3]);
			if(a[1].num<a[2].num) swap(a[1],a[2]);
			val[i].mx=a[1].num;
			val[i].mx_id=a[1].id;
			val[i].mid=a[2].num;
			val[i].mid_id=a[2].id;
			val[i].mn=a[3].num;
			val[i].mn_id=a[3].id;
			//cout<<val[i].mx<<" "<<val[i].mx_id<<" "<<val[i].mid<<" "<<val[i].mid_id<<" "<<val[i].mn<<" "<<val[i].mn_id<<"\n";
		}
		sort(val+1,val+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[val[i].mx_id]!=n/2){
				ans+=val[i].mx;
				cnt[val[i].mx_id]++;
			}
			else{
				ans+=val[i].mid;
				cnt[val[i].mid_id]++;
			}
		}
		cout<<ans<<"\n";
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}


