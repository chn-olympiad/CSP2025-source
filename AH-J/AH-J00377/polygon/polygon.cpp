//'meet in the middle'is going out the mountain!!!
#include<bits/stdc++.h>
using namespace std;
struct awa{
	int sum,num,mxn;
};
const int mod=998244353;
int n,a[5005];
vector<awa>d1;
int ans;
void ldfs(int l,int r,int choose,int sum,int mxx){
	if(l>r){
		d1.push_back({sum,choose,mxx});
		return ;
	}
	ldfs(l+1,r,choose,sum,mxx);
	ldfs(l+1,r,choose+1,sum+a[l],max(mxx,a[l]));
	return ;
}
void rdfs(int l,int r,int choose,int sum,int mxx){
	if(l>r){
		int cnt=0,cx=0;
		for(awa v : d1)if(v.num+choose>=2)if(v.sum+sum>(max(mxx,v.mxn)<<1))cx++;
		ans=(ans+cx)%mod;
		return ;
	}
	rdfs(l+1,r,choose,sum,mxx);
	rdfs(l+1,r,choose+1,sum+a[l],max(mxx,a[l]));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int mid=(1+n)>>1;
	ldfs(1,mid,0,0,0);
	rdfs(mid+1,n,0,0,0);	
	cout<<ans<<endl;
	return 0;
}
