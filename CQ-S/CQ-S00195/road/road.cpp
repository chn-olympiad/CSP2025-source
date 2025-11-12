#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
struct node{
	long long f,t,money,id;
}s[1000001],need[1000001],ss[1000001],need1[1000001];
//永远只会选择一个乡镇 
long long mon[100];
bool cmp(node o,node p){
	return o.money<p.money;
}
bool cmp1(node o,node p){
	return o.id<p.id;
}
long long dad[100001],sh[100001];
long long fin(long long p){
	while(p!=dad[p]){
		dad[p]=dad[dad[p]];
		p=dad[p];
	}
	return p;
}
long long sk(long long k,long long size){
	long long ans=0;
	long long num=0;
	sort(s+1,s+size+1,cmp);
	for(long long i=1;i<=size;i++){
		if(fin(s[i].f)==fin(s[i].t))continue;
		ans+=s[i].money;
		dad[fin(s[i].f)]=fin(s[i].t);
		num++;
		if(k==0){
			need[num].f=s[i].f;
			need[num].money=s[i].money;
			need[num].t=s[i].t;
		}
		if(num>=n-1){
			return ans;
		}	
	}
	return ans;
} 
long long sk1(int k,int size){
	long long ans=0;
	long long num=0;
	sort(ss+1,ss+size+1,cmp);
//	cout<<"注意:\n"; 
	for(long long i=1;i<=size;i++){
		if(fin(ss[i].f)==fin(ss[i].t))continue;
		ans+=ss[i].money;
		num++;
		need1[num].f=ss[i].f;
		need1[num].money=ss[i].money;
		need1[num].t=ss[i].t;
//		cout<<fin(ss[i].f)<<' '<<fin(ss[i].t)<<" num="<<ss[i].f<<' '<<ss[i].t<<" "<<ss[i].money<<'\n';
		dad[fin(ss[i].f)]=fin(ss[i].t);
	}
	return ans;
} 
long long dian[12][100001];
int main(){
	//从点权最小的点开始krsk，链式前向星 
	freopen("road.in","r",stdin);
	freopen("road.in","w",stdout);
	cin>>n>>m>>k;
	int ui,vi,wi;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&s[i].f,&s[i].t,&s[i].money);
	}
	for(int i=1;i<=n;i++){
		dad[i]=i;
		sh[i]=1;
	}
	for(int j=1;j<=k;j++){
		for(int i=0;i<=n;i++){
			if(i==0){
				cin>>mon[j];
				continue;
			}
			cin>>dian[j][i];
		}
	}
	long long num=sk(0,m); 
//	cout<<"num="<<num<<'\n';
	long long nn=n;
	for(int kk=1;kk<=k;kk++){
		for(int i=1;i<=n+kk;i++){
			dad[i]=i;
			sh[i]=1;
		}
		for(int i=1;i<nn;i++){
			ss[i].f=need[i].f;
			ss[i].money=need[i].money;
			ss[i].t=need[i].t;
		}
		for(int i=nn;i<n+nn;i++){
			ss[i].f=n+kk;
			ss[i].money=dian[kk][i-nn+1];
			ss[i].t=i-nn+1;
		}
//		for(int i=1;i<n+nn;i++){
//			cout<<ss[i].f<<" "<<ss[i].t<<' '<<ss[i].money<<'\n';
//		}		
//		
//		cout<<'\n';
//		system("pause");
		long long ts=sk1(0,n+nn-1);
		if(ts+mon[kk]<=num){
			nn++;
			num=ts+mon[kk];
			for(int i=1;i<nn;i++){
				need[i].f=need1[i].f;
				need[i].money=need1[i].money;
				need[i].t=need1[i].t;
			}
		}
	}
	cout<<num;
	
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
0 1 1 9 1
*/

