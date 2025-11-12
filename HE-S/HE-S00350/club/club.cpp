#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+10;

ll t,n,x,y,z;

struct node{
	
	ll mx,mxid,mx2;
	ll val;
}p[N];

inline bool cmp(node x,node y){
	
	return x.val<y.val;
}

inline void work(ll id){
	
	for(int i=1;i<=n;i++){
		
		if(p[i].mxid!=id) p[i].val=0x3f3f3f3f3f3f3f3f;
	}
	
	return;
}

int main(){
	
	//突破点：贪心地想，每个人一定能被分到他最喜欢的两个部门中的其中一个。
	//证明：因为每个部门的人数不超过 n/2，而每个人都有两种选择，所以正确。
	//思路：只保留每个人最喜欢的前两个部门，再统计并分讨。 
	//我们发现，最后不能满足条件的部门一定只有一个。
	//所以我们把这个不能满足的部门按照 mx-mx2 进行排序，那么这个值更小的就改其他部门。 
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		
		cin>>n;
		ll cnt1=0,cnt2=0,cnt3=0,ans=0;
		
		for(int i=1;i<=n;i++){
			
			cin>>x>>y>>z;
			p[i].mx=max(x,max(y,z));
			
			if(x==p[i].mx) p[i].mxid=1,p[i].mx2=max(y,z);
			else if(y==p[i].mx) p[i].mxid=2,p[i].mx2=max(x,z);
			else p[i].mxid=3,p[i].mx2=max(x,y);
			
			if(p[i].mxid==1) cnt1++;
			else if(p[i].mxid==2) cnt2++;
			else cnt3++;
			
			p[i].val=p[i].mx-p[i].mx2;
			ans+=p[i].mx;
		}
		
		//全部都能满足条件 
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
			
			cout<<ans<<'\n';
			continue;
		}
		
		ll op;
		if(cnt1>n/2) work(1),op=cnt1;
		else if(cnt2>n/2) work(2),op=cnt2;
		else work(3),op=cnt3;
		
		sort(p+1,p+1+n,cmp);
		
		for(int i=1;i<=op-n/2;i++) ans-=p[i].val;
		cout<<ans<<'\n';
	}
	
	return 0;
}
//15:32 meaw!
