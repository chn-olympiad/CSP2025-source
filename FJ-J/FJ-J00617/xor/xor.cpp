#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long yh(long long b,long long c){
	int aa[100],bb[100],cc[100];
	int e=0,w=0;
	while(b!=0){
		e++;
		aa[e]=b%2;
		b/=2;
	}
	while(c!=0){
		w++;
		bb[w]=c%2;
		c/=2;
	}
	int ee=min(e,w);
	for(int i=1;i<=ee;i++){
		if(bb[i]==aa[i]){
			cc[i]=0;
		}else if(bb[i]!=aa[i]){
			cc[i]=1;
		}
	}
	if(e>w){
		for(int i=ee+1;i<=e;i++){
			cc[i]=aa[i];
		}
	}else if(e<w){
		for(int i=ee+1;i<=w;i++){
			cc[i]=bb[i];
		}
	}
	int n=max(w,e);
	long long sum=0,cs=0;
	for(int i=1;i<=n;i++){
		sum=sum+pow(2,cs)*cc[i];
		cs++;
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,l=0,r=0,y=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			l++;
		}
		if(a[i]<=1){
			r++;
		}
		if(a[i]==0){
			y++;
		}
	}
	if(l==n){
		if(k==0){
			cout<<n/2;
			return 0;
		}
	}
	if(r==n){
		if(k==0){
			cout<<y+l/2;
			return 0;
		}else{
			cout<<l;
			return 0;
		}
	}
	int sum=0,q=a[1];
	bool bd=1;
	for(int i=2;i<=n;i++){
		if(q==0&&!bd){
			q=a[i];
			bd=1;
			continue;
		}
		if(q==k){
			sum++;
			q=a[i];
			continue;
		}
		if(yh(q,a[i])==k||a[i]==k){
			sum++;
			q=0;
			bd=0;
		}else if(yh(q,a[i])!=k||a[i]!=k){
			q=yh(q,a[i]);
		}
	}
	if(q==k){
		sum++;
	}
	cout<<sum;
	return 0;
} 
