//GZ-S00462 贵阳市第三中学 陈威豪 
#include<bits/stdc++.h>
using namespace std;
#define luo_xing main
#define push_back pb
typedef long long ll;
const int N=1e5+10;
int T;
int n,s1,s2,s3;
struct node{
	int c,num,ai;
}ans[N*2];
struct luo{
	int a1,a2,a3;
}a[N];
struct edge{
	int x,ai;
}d1[N],d2[N],d3[N];
bool v[N];
ll sum=0;
bool cmp(node ab,node cd){
	return ab.c>cd.c;
}
stack<int> q;
void dfs(int i,int j,int k,ll s){
//	cout<<i<<' '<<j<<' '<<k<<' '<<s<<endl;
//	cout<<s1<<" "<<s2<<" "<<s3<<'\n';
	while(v[d1[i].ai]) i++;
	while(v[d2[j].ai]) j++;
	while(v[d3[k].ai]) k++;
	if(i>n && j>n && k>n){
		sum=max(sum,s);
		return;
	}
	if(s1<n/2){
		v[d1[i].ai]=1;
		s1++;
		dfs(i+1,j,k,s+d1[i].x);
		s1--;
		v[d1[i].ai]=0;
	}
	if(s2<n/2){
		v[d2[j].ai]=1;
		s2++;
		dfs(i,j+1,k,s+d2[j].x);
		s2--;
		v[d2[j].ai]=0;
	}
	if(s3<n/2){
		v[d3[k].ai]=1;
		s3++;
		dfs(i,j,k+1,s+d3[k].x);
		s3--;
		v[d3[k].ai]=0;
	}
	return;
}
void solve(){
	cin>>n;
	int p=0;
	for(int i=1;i<=n;i++){
		int b,c,d;
		cin>>b>>c>>d;
		d1[i].x=b,d1[i].ai=i;
		d2[i].x=c,d2[i].ai=i;
		d3[i].x=d,d3[i].ai=i;
		a[i].a1=b;
		a[i].a2=c;
		a[i].a3=d;
		if(b>c) swap(b,c);
		if(c>d) swap(c,d);
		if(b>c) swap(b,c);
		ans[++p].c=c-b,ans[p].num=2,ans[p].ai=i;
		ans[++p].c=d-b,ans[p].num=1,ans[p].ai=i;
	}
	if(n<=10){
		dfs(1,1,1,0);
		cout<<sum<<endl;
		return;
	}
	sort(ans+1,ans+p+1,cmp);
	for(int i=1;i<=p;i++){
		int to=ans[i].ai,m=ans[i].num;
		if(v[to]==0){
			if(m==1){
				if(a[to].a3>=a[to].a2 && a[to].a3>=a[to].a1 && s3<n/2){
					v[to]=1;
					s3++;
					sum+=a[to].a3;
					q.push(3);
				}else if(a[to].a2>=a[to].a1 && a[to].a2>=a[to].a3 && s2<n/2){
					v[to]=1;
					s2++;
					sum+=a[to].a2;
					q.push(2);
				}else if(a[to].a1>=a[to].a2 && a[to].a1>=a[to].a3 && s1<n/2){
					v[to]=1;
					s1++;
					sum+=a[to].a1;
					q.push(1);
				}
			}else{
				if(((a[to].a3>=a[to].a2 && a[to].a3<=a[to].a1) || (a[to].a3>=a[to].a1 && a[to].a3<=a[to].a2)) && s3<n/2){
					v[to]=1;
					s3++;
					sum+=a[to].a3;
					q.push(3);
				}else if(((a[to].a2>=a[to].a3 && a[to].a2<=a[to].a1) || (a[to].a2>=a[to].a1 && a[to].a2<=a[to].a3)) && s2<n/2){
					v[to]=1;
					s2++;
					sum+=a[to].a2;
					q.push(2);
				}else if(((a[to].a1>=a[to].a2 && a[to].a1<=a[to].a3) || (a[to].a1>=a[to].a3 && a[to].a1<=a[to].a2)) && s1<n/2){
					v[to]=1;
					s1++;
					sum+=a[to].a1;
					q.push(1);
				}
			}
		}
		cout<<ans[i].c<<" "<<m<<" "<<to<<' '<<sum<<endl;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			sum+=min(a[i].a1,min(a[i].a2,a[i].a3));
		}
	}
	while(!q.empty()){
		cout<<q.top()<<" ";
		q.pop();
	}
	cout<<endl;
	cout<<sum<<endl;
	return;
}
int luo_xing(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
		s1=0,s2=0,s3=0;
		sum=0;
		for(int i=1;i<=n;i++){
			v[i]=0;
		}
	}
	return 0;
}
