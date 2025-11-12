#include<bits/stdc++.h>
using namespace std;

int n,k,ans=0,len=0;
int a[100006],sum[100006];
struct ss{
	int ll;
	int rr;
}aans[1000006];

bool cmp(ss xx,ss yy){
	if(xx.rr==yy.rr)return xx.ll<yy.ll;
	return xx.rr<yy.rr;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
	}
	if(k==0&&f==1){
		cout<<n/2;
		return 0;
	}
	if(k<=1){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
				
				else if(a[i+1]==1){
					ans++;
					i++;
				}
			}
		}
		else {
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
				else if(a[i+1]!=a[i]){
					ans++;
					i++;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	
	sum[1]=a[1];
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]^a[i];	
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if((r==l&&a[l]==k)||(l!=r&&sum[r+1]^sum[l-1]==k)){
				aans[++len].ll=l;
				aans[len].rr=r;
			}
		}
	}
	for(int i=1;i<=len;i++){
		cout<<aans[i].ll<<" "<<aans[i].rr<<endl;
	}
	sort(aans+1,aans+len+1,cmp);
	int kk=aans[1].rr,cnt=1;
	for(int i=2;i<=len;i++){
		if(aans[i].ll>kk){
			cnt++;
			kk=aans[i].rr;
		}
	}
	cout<<cnt;
	return 0;
}
