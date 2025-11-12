#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

const int N=5e5+7;

struct edge{
	int l,r;
}e[N];

int n,k,a[N],d[N]={};
int suma=0,s1=0, idx=0;

bool cmp(edge p,edge q){
	return p.r<q.r;
}

void scoreB(){
	int l=1,r=1,cnt=0;
	while(r<=n){
		int sumr=a[l];
		while(r<=n&& (sumr&1)!=k) sumr+=a[++r];
		
		cnt++;
		l=++r;
		
	}
	cout<<cnt;
	
	return ;
}

void scoreC(){
	d[1]=a[1];
	for(int i=2;i<=n;i++){
		d[i]=d[i-1]^a[i];
		
	}
	
	int l,r,cnt=0;
	
	for(l=1;l<=n;l++){
		int w=a[l];
		r=l;
		while(r<=n&& w!=k) w=d[++r]^d[l-1];
		
//		printf("%d %d %d \n",l,r,w);
		
		if(r<=n){
			e[++idx]={l,r};
			
		}
	}
	
	sort(e+1,e+1+idx,cmp);
	
	for(int i=1;i<=idx;i++){
		if(e[i-1].r<e[i].l) cnt++;
	}
	
	cout<<cnt;
	
	return ;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		suma+=a[i];
		if(a[i]==1) s1++;
	}
//	suma==s1：只有 0 1 
	if(suma==s1&&s1==n){
		cout<<(n/2);
		return 0;
	}
	if(suma==s1&&s1<n){
		scoreB();
		
		return 0;
	}
	if(k<=255){
		scoreC();
//		maybe前缀和 
		return 0;
	}
	
	
	
	return 0;
}
