#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int T,n,s[3],c[N],p[N];
struct Node{
	int a,b,c;
}a[N];
vector<pair<int,int> > v;
int chose(Node& x){
	pair<int,int> tmp[3]={{x.a,0},{x.b,1},{x.c,2}};
	sort(tmp,tmp+3,greater<pair<int,int> >());
	return tmp[0].second;
}int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		long long res=0;
		cin>>n,s[0]=s[1]=s[2]=0;
		for(int i=1;i<=n;i++)	cin>>a[i].a>>a[i].b>>a[i].c;
		v.clear();
		for(int i=1;i<=n;i++){
			c[i]=chose(a[i]);
			s[c[i]]++,res+=(p[i]=(c[i]?(c[i]==1?a[i].b:a[i].c):a[i].a));
		}int idx=0;
		for(int i=1;i<3;i++)	if(s[i]>s[idx])	idx=i;
		if(s[idx]>n/2){
			
			for(int i=1;i<=n;i++){
				if(c[i]!=idx)	continue;
				if(idx!=0)	v.push_back({p[i]-a[i].a,i});
				if(idx!=1)	v.push_back({p[i]-a[i].b,i});
				if(idx!=2)	v.push_back({p[i]-a[i].c,i});
			}sort(v.begin(),v.end(),less<pair<int,int> >());
			int vidx=0;
			
			while(s[idx]>n/2){
				if(p[v[vidx].second]!=-1){
					res-=v[vidx].first,p[v[vidx].second]=-1;
					s[idx]--;
				}vidx++;
			}
			
		}cout<<res<<"\n";
	}cout.flush();
	
	fclose(stdin);
	fclose(stdout);
}/*

*/
