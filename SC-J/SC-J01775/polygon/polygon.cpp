#include<bits/stdc++.h>
using namespace std;
const long long mo=998244353;
long long sum=0;
int a[5001],num[5001],th[5001],p[5001],f;
void dfs(int dep,long long s,int mx,int n,int tth){
	if(dep>n) return;
	long long ss=s,tyt=num[dep]; 
	while(ss<=mx*2&&tyt>0){
		ss+=a[dep];
		tyt--;
	}
	if(s>mx*2){
		sum+=tyt;
		sum%=mo;
	}
	for(int i=tth+1;i<=f;i++){
		dfs(th[i],s+a[dep]*num[dep],a[th[i]],n,i);
	}
	return;
}
bool cmp(int a,int b){
	return a<b;
}
signed main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n,t,s;
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	t=1,p[1]=a[1],f=1;
	for(int i=1;i<=n;i++){
		if(a[i+1]==a[i]){
			num[a[i]]++;
		}
		else{
			th[t]=i+1;
			t++;
			f++;
			p[f]=a[1+1];
		}
	}
	dfs(1,0,a[1],n,1);
	cout<<sum;
	return 0;
}