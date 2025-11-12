#include <bits/stdc++.h>
using namespace std;
struct stru{
	long long st,en;
}hd[10005];
bool cmp(stru a,stru b){return a.en<b.en;}
long long n,k;
long long a[500005];
long long s[500005];
bool task_A=true;
bool task_B=true;
long long ct0=0,ct1=0,ct11=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	a[0]=s[0]=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		if(a[i]!=1) task_A=false;
		if(a[i]>1) task_B=false;
		if(a[i]==1) ct1++;
		else ct0++;
		if(a[i]==1&&a[i-1]==1) ct11++;
	}
	if(task_A) cout<<n/2;//ai=1,k=0
	else if(task_B){//ai<=1,k<=1
		if(k==1){
			cout<<ct1;
		}else{
			cout<<ct0+ct11;
		}
	}else{
		long long ct=0;
		for(long long i=1;i<=n;i++){
			for(long long j=i;j<=n;j++){
				if((s[i-1]^s[j])==k){
					hd[ct].st=i;
					hd[ct].en=j;
					ct++;
				}
			}
		}
		sort(hd,hd+ct,cmp);
		long long last=0,ans=0;
		for(long long i=0;i<ct;i++){
			if(last<hd[i].st){
				last=hd[i].en;
				ans++;
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
