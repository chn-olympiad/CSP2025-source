#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010][3];
struct node{
	int id,s,k;
	bool operator  < (const node &A) const{
		int cnt,cntA;
		if(k==1)	cnt=min(a[id][k]-a[id][2],a[id][k]-a[id][3]);
		if(k==2)	cnt=min(a[id][k]-a[id][1],a[id][k]-a[id][3]);
		if(k==3)	cnt=min(a[id][k]-a[id][2],a[id][k]-a[id][1]);
		if(k==1)	cntA=min(a[A.id][k]-a[A.id][2],a[A.id][k]-a[A.id][3]);
		if(k==2)	cntA=min(a[A.id][k]-a[A.id][1],a[A.id][k]-a[A.id][3]);
		if(k==3)	cntA=min(a[A.id][k]-a[A.id][2],a[A.id][k]-a[A.id][1]);
		if(cnt<cntA) return true;
		if(cnt==cntA && id<A.id) return true;
		return false;
	}
	bool operator  > (const node &A) const{
		int cnt,cntA;
		if(k==1)	cnt=min(a[id][k]-a[id][2],a[id][k]-a[id][3]);
		if(k==2)	cnt=min(a[id][k]-a[id][1],a[id][k]-a[id][3]);
		if(k==3)	cnt=min(a[id][k]-a[id][2],a[id][k]-a[id][1]);
		if(k==1)	cntA=min(a[A.id][k]-a[A.id][2],a[A.id][k]-a[A.id][3]);
		if(k==2)	cntA=min(a[A.id][k]-a[A.id][1],a[A.id][k]-a[A.id][3]);
		if(k==3)	cntA=min(a[A.id][k]-a[A.id][2],a[A.id][k]-a[A.id][1]);
		if(cnt>cntA) return true;
		if(cnt==cntA && id>A.id) return true;
		return false;
	}
};
int check(int x,int y,int z){
	if(x>y && x>z)	return 1;
	if(y>x && y>z)	return 2;
	if(z>x && z>y)	return 3;
	return 4;
}
priority_queue<node,vector<node>,greater<node> >f,s,t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for( ;T--; ){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++){
			int k=check(a[i][1],a[i][2],a[i][3]);
			if(k==1){
				node cnt;
				cnt.id=i,cnt.s=a[i][1],cnt.k=1;
				f.push(cnt);
				if(f.size()>n/2){
					node c=f.top();f.pop();
					if(a[c.id][2]>a[c.id][3])  s.push(c);
					else if(a[c.id][3]>a[c.id][2])  t.push(c);
					else if(s.size()<t.size())  s.push(c);
					else  t.push(c);					
				}
			}
			if(k==2){
				node cnt;
				cnt.id=i,cnt.s=a[i][2],cnt.k=2;
				s.push(cnt);
				if(s.size()>n/2){
					node c=s.top();s.pop();
					if(a[c.id][1]>a[c.id][3])  f.push(c);
					else if(a[c.id][3]>a[c.id][1]) t.push(c);
					else if(f.size()<t.size()) f.push(c);
					else t.push(c);
				}
			}
			if(k==3){
				node cnt;
				cnt.id=i,cnt.s=a[i][3],cnt.k=3;
				t.push(cnt);
				if(t.size()>n/2){
					node c=t.top();t.pop();
					if(a[c.id][2]>a[c.id][1]) s.push(c);
					else if(a[c.id][1]>a[c.id][2]) f.push(c);
					else if(s.size()<f.size()) s.push(c);
					else  f.push(c);
				}
			}			
			if(k==4){
				int p=check(f.size(),s.size(),t.size());
				node cnt;
				cnt.id=i,cnt.s=a[i][p],cnt.k=p%3;
				if(p==1||p==4) f.push(cnt);
				if(p==2) s.push(cnt);
				if(p==3) t.push(cnt);	
			}
		} 
		int ans=0;
		int fl=f.size(),sl=s.size(),tl=t.size();
		for( ;fl--;)	
			ans+=a[f.top().id][1],f.pop();
		for( ;sl--;)
			ans+=a[s.top().id][2],s.pop();
		for( ;tl--;)
			ans+=a[t.top().id][3],t.pop();
		printf("%d\n",ans);
	}
}
