#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n,k,a[600000],xors[600000],cnt,ans=0;
bool speA=1,speB=1;
pii subse[1000000];
bool cmp(pii a,pii b){return a.first<b.first;}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];xors[i]=xors[i-1]^a[i];
		if(a[i]!=1)speA=0;
		if(a[i]!=0&&a[i]!=1)speB=0; 
	}
	if(speA){
		//k==0 
		cout<<n/2;
	} 
	else if(speB){
		//k<2
		int cnt1=0,cnt0=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)cnt1++;
				else cnt0++;
			}
		if(k)cout<<cnt1;
		else cout<<max(cnt0,cnt1/2);
	} 
	else{
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				if(xors[r]^xors[l-1]==k){
					subse[++cnt]={l,r};
				}
			} 
		}
		sort(subse+1,subse+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			int cntsubse=0;
			for(int j=i+1;j<=cnt;j++){
				if(subse[i].second<=subse[j].first)continue;
				cntsubse++;
			} 
			ans=max(ans,cntsubse);
		}
		cout<<ans;
	}
}//[0,30]
