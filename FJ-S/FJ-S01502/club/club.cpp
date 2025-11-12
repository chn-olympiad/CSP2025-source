#include<bits/stdc++.h>
#define int long long
using namespace std;
struct tk{
	int an1,an2,an3,man,mcn,ccn;
}kt;
int n;
int cn1,cn2,cn3,mmcn,mman,ans,cccn;
vector<tk> a;
bool cmp(tk x,tk y){
	return x.ccn<y.ccn;
}
void ma(){
	kt.man=max(kt.an1,max(kt.an2,kt.an3));
	if(kt.man==kt.an1){
		kt.mcn=1;cn1++;
	}
	else if(kt.man==kt.an2) {
		kt.mcn=2;cn2++;
	}
	else{
		kt.mcn=3;cn3++;
	}
	kt.ccn=2*kt.man-(kt.an1+kt.an2+kt.an3-min(min(kt.an1,kt.an2),kt.an3));
	ans+=kt.man;
}
void ch(){
	for(int i=0;i<n;i++){
		if(a[i].mcn!=mmcn){
			a.erase(a.begin()+i);
		}
	}
}
void solve(){
	a.clear();
	cn1=cn2=cn3=0;ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>kt.an1>>kt.an2>>kt.an3;
		ma();
		a.push_back(kt);
	}
	mman=max(max(cn1,cn2),cn3);
	if(mman==cn1){
		mmcn=1;
	}
	else if(mman==cn2) {
		mmcn=2;
	}
	else{
		mmcn=3;
	}
	cccn=mman-(n/2);
	if(mman<=(n/2)){
		cout<<ans<<'\n';
		return;
	}
	ch();
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<cccn;i++){
		ans-=a[i].ccn;
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

