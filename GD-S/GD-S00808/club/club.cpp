#include<bits/stdc++.h>
#define int long long
using namespace std;
struct stu{
	int a,b,c,ia,ib,ic;
}s[100010];
int n;
bool b[100010]; 
vector<int> am;
vector<int> bm;
vector<int> cm;
bool cmp1(int x,int y){	return s[x].ia>s[y].ia;}
bool cmp2(int x,int y){	return s[x].ib>s[y].ib;}
bool cmp3(int x,int y){	return s[x].ic>s[y].ic;}
void work(){
	am.clear();
	bm.clear();
	cm.clear();
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		b[i]=false;
		s[i]={x,y,z,x-max(y,z),y-max(x,z),z-max(x,y)};
		if(x>=y && x>=z) am.push_back(i);
		if(y>=x && y>=z) bm.push_back(i);
		if(z>=x && z>=y) cm.push_back(i);
	}
	sort(am.begin(),am.end(),cmp1);
	int len=n/2,ans=0;
	int amlen=am.size();
	for(int i=0;i<min(amlen,len);i++){
		ans+=s[am[i]].a;
		b[am[i]]=true;
	}
	for(int i=len;i<amlen;i++){
		s[am[i]].ib=s[am[i]].b-s[am[i]].c;
		s[am[i]].ic=s[am[i]].c-s[am[i]].b;
		if(s[am[i]].b>=s[am[i]].c) bm.push_back(am[i]);
		if(s[am[i]].c>=s[am[i]].b) cm.push_back(am[i]);
	}
	int amemp=max(0ll,len-amlen);
	
	sort(bm.begin(),bm.end(),cmp2);
	len=n/2;
	int bmlen=bm.size(),bmemp=n/2,cmemp=n/2;
	for(int i=0;i<min(bmlen,len);i++){
		if(b[bm[i]]==true) continue;
		ans+=s[bm[i]].b;
		b[bm[i]]=true;
		bmemp--;
	}
	for(int i=len;i<bmlen;i++){
		if(b[bm[i]]==true) continue;
		if(amemp>0 && s[bm[i]].a>s[bm[i]].c)
			ans+=s[bm[i]].a,
			b[bm[i]]=true,
			amemp--;
		else
			s[bm[i]].ic=s[bm[i]].c-s[bm[i]].a,
			cm.push_back(bm[i]);
	}

	sort(cm.begin(),cm.end(),cmp3);
	len=cmemp;
	int cmlen=cm.size();
	for(int i=0;i<min(cmlen,len);i++){
		if(b[cm[i]]==true) continue;
		ans+=s[cm[i]].c;
		b[cm[i]]=true;
		cmemp--;
	}
	for(int i=len;i<cmlen;i++){
		if(b[cm[i]]==true) continue;
		if(amemp>0 && s[cm[i]].a>s[cm[i]].b)
			ans+=s[cm[i]].a,
			b[cm[i]]=true,
			amemp--;
		else
			ans+=s[cm[i]].b,
			b[cm[i]]=true,
			bmemp--;
	}
	cout<<ans<<'\n';
}
signed main(){
	std::ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) work();
	return 0;
}
