#include<bits/stdc++.h>
using namespace std;
struct node{
	int da,db,dc;
};
bool cmpa(node a,node b){
	return min((a.da-a.db),(a.da-a.dc))<min((b.da-b.db),(b.da-b.dc));
}
bool cmpb(node a,node b){
	return min((a.db-a.da),(a.db-a.dc))<min((b.db-b.da),(b.db-b.dc));
}
bool cmpc(node a,node b){
	return min((a.dc-a.da),(a.dc-a.db))<min((b.dc-b.da),(b.dc-b.db));
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		vector<node> a;
		vector<node> b;
		vector<node> c;
		int n,sum=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			node k;
			cin>>k.da>>k.db>>k.dc;
			if(k.da>=k.db&&k.da>=k.dc){
				a.push_back(k);	
				ans+=k.da;
			}else if(k.db>=k.da&&k.db>=k.dc){
				b.push_back(k);
				ans+=k.db;
			}else{
				c.push_back(k);
				ans+=k.dc;
			}
		}
		sort(a.begin(),a.end(),cmpa);
		sort(b.begin(),b.end(),cmpb);
		sort(c.begin(),c.end(),cmpc);
		int f=0;
		if(a.size()>n/2){
			f=a.size()-n/2-1;
			for(int i=0;i<=f;i++){
				sum+=min((a[i].da-a[i].db),(a[i].da-a[i].dc));
			}
		}else if(b.size()>n/2){
			f=b.size()-n/2-1;
			for(int i=0;i<=f;i++){
				sum+=min((b[i].db-b[i].da),(b[i].db-b[i].dc));
			}
		}else if(c.size()>n/2){
			f=c.size()-n/2-1;
			for(int i=0;i<=f;i++){
				sum+=min((c[i].dc-c[i].da),(c[i].dc-c[i].db));
			}
		}
		cout<<ans-sum<<endl;
	}
	return 0;
}
