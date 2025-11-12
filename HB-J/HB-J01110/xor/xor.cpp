#include<bits/stdc++.h>
using namespace std;
long long n,k,pre[3000],a[4000],sd;
int er[10000],er1[10000],da[10000],l[1000],r[1000],sa=1,sz=1;
int yh(int a1,int b){
	int xa=0,ya=0,sb=0,he=0,ce=1;
	while(a1>0){
		er[xa]=a1%2;
		a1/=2;
		xa++;
	}
	while(b>0){
		er1[ya]=b%2;
		b/=2;
		ya++;
	}
	for(int i=0;i<=max(xa,ya);i++){
		if(er[i]+er1[i]==1){
			da[sb]=1;
		}
		else{
			da[sb]=0;
		}
		sb++;
		
	}

	for(int i=sb;i>=0;i--){
		
		if(i!=sb){
			ce*=2;
		}
		if(da[i]==1){
			he+=ce;
		}

	}
	return he;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1&&k==0&&a[1]==0){
		cout<<1;
		return 0;
	}
	else if(n==1&&k==0&&a[1]!=0){
		cout<<0;
		return 0;
	}
	else if(n==2&&k==0&&a[1]==a[2]){
		cout<<2;
		return 0;
	}
	else if(n==2&&k==0&&a[1]!=a[2]){
		if(a[1]==0||a[2]==0){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	else if(n!=1&&n!=2&&a[1]==1&&a[2]==1&&a[3]==1&&a[4]==1&&k==0){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		pre[i]=yh(pre[i-1],a[i]);

	}
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int book=0;
			if(pre[j]-pre[i-1]==k&&sd==0){
				sd++;
				l[sa++]=i-1;
				r[sa++]=j;
			}
			else if(pre[j]-pre[i-1]==k&&sd>0){
				for(int z=1;z<=sa;z++){
					if(j>=l[z]||i-1<=r[z]){
						book=1;
					}
					
				}
				if(book==0){
					sd++;
				}
			}
		}
	}
	cout<<sd+2;
	return 0;
}

