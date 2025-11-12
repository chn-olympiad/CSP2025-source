#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long h=0;
long long a[500100]={0};
long long t[500100]={0};
long long p[500100]={0};
bool f;
long long maxn=0;
void ll(long long s){
	int u;
	int kk=0;
	while(s>0){
		u=s%2;
		s=s/2;
		p[kk]=u;
		kk++;
	}
	return ;
}
int cmp(long long s){
	int u;
	int kk=0;
	f=0;
	while(s>0){
		u=s%2;
		s=s/2;
		t[kk]=(t[kk]+u)%2;
		if(t[kk]!=p[kk]){
			f=1;
		}
		kk++;
	}
	while(kk<=maxn && f==0){
		if(t[kk]!=p[kk]){
			f=1;
		}
		kk++;
	}
	if(kk>maxn){
		maxn=kk;
	}
	if(f==0){
		return 1;
	}else{
		return 0;
	}
}
void cnp(){
	for(int i=0;i<maxn;i++){
		t[i]=0;
	}
	maxn=0;
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	ll(m);
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(cmp(a[i])==1){
			h++;
			cnp();
		}
	}
	cout<<h;
	return 0;
}
