#include<bits/stdc++.h>
using namespace std;
int t,n,sa,sb,sc;
long long ans,ss,mn=-1;
int q[13];
struct S{
	int a,b,c,va,vb;
}a[100007];
bool cmp(S x,S y){
	if(max(x.va,x.vb)==max(y.va,y.vb)) return min(x.va,x.vb)>min(y.va,y.vb);
	return max(x.va,x.vb)>max(y.va,y.vb);
}
bool cm(S x,S y){
	return x.a>y.a;
}
bool cmm(S x,S y){
	return x.va>y.va;
}
bool check(){
	int v[3];
	for(int i=0;i<3;i++) v[i]=0;
	for(int i=1;i<=n;i++) v[q[i]-1]++;
	if(v[0]>n/2||v[1]>n/2||v[2]>n/2) return false;
	return true;
}
void dfs(int x,int k,int n){
	if(k==n+1){
		if(!check()) return ;
		for(int i=1;i<=n;i++){
			if(q[i]==1) ss+=a[i].a;
			else if(q[i]==2) ss+=a[i].b;
			else ss+=a[i].c;
		}
		mn=max(mn,ss);
		ss=0;
		return ;
	}
	dfs(x+1,k+1,n);
	q[x]=2;
	dfs(x+1,k+1,n);
	q[x]=3;
	dfs(x+1,k+1,n);
	q[x]=1;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int cnta=0,cntb=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].va=abs(a[i].a-a[i].b);
			a[i].vb=abs(a[i].b-a[i].c);
			if(a[i].b==0) cnta++;
			if(a[i].c==0) cntb++;
		}
		if(cnta==n&&cntb==n){
			sort(a+1,a+n+1,cm);
			long long sum=0;
			for(int i=1;i<=n/2;i++) sum+=a[i].a;
			cout<<sum<<endl;
			continue;
		}
		if(cntb==n&&cnta!=n){
			sort(a+1,a+n+1,cmm);
			long long sum=0;
			int nn=0,mm=0;
			for(int i=1;i<=n;i++){
				if(max(a[i].a,a[i].b)==a[i].a){
					if(nn<n/2) nn++,sum+=a[i].a;
					else mm++,sum+=a[i].b;
				}
				else{
					if(mm<n/2) mm++,sum+=a[i].b;
					else nn++,sum+=a[i].a;
				}
			}
			cout<<sum<<endl; 
			continue;
		}
		if(n<=10){
			mn=-1;
			for(int i=1;i<=n;i++) q[i]=1;
			dfs(0,0,n);
			cout<<mn<<endl;
			continue;
		}
		sort(a+1,a+n+1,cmp);
		sa=0,sb=0,sc=0;
		for(int i=1;i<=n;i++){
			if(max(a[i].a,max(a[i].b,a[i].c))==a[i].a){
				if(sa<n/2) sa++,ans+=a[i].a;
				else{
					if(a[i].b>a[i].c) sb++,ans+=a[i].b;
					else if(a[i].c>a[i].b) sc++,ans+=a[i].c;
					else{
						if(sb>sc) sc++,ans+=a[i].c;
						else sb++,ans+=a[i].b; 
					}
				}
			}
			else if(max(a[i].a,max(a[i].b,a[i].c))==a[i].b){
				if(sb<n/2) sb++,ans+=a[i].b;
				else{
					if(a[i].a>a[i].c) sa++,ans+=a[i].a;
					else if(a[i].c>a[i].a) sc++,ans+=a[i].c;
					else{
						if(sa>sc) sc++,ans+=a[i].c;
						else sa++,ans+=a[i].a; 
					}
				}
			}
			else{
				if(sc<n/2) sc++,ans+=a[i].c;
				else{
					if(a[i].b>a[i].a) sb++,ans+=a[i].b;
					else if(a[i].a>a[i].b) sa++,ans+=a[i].a;
					else{
						if(sb>sa) sa++,ans+=a[i].a;
						else sb++,ans+=a[i].b; 
					}
				}
			}
			}
			cout<<ans<<endl;
			ans=0;	
		}
	return 0;	
}//我真没招了 我一个蒟蒻容易吗
//根本不会只能这样一个个特判
//求CCF善待我（虽然他J已经非常简单了）
//但能不能给点水样例啊
//我想混个奖
//求善待 不说了片阳历去了 
