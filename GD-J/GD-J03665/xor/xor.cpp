#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[500001];
int s[500001];
pair<int,int> b[500001];
int bb=0,aa=0,m,ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(bb>=0&&a[i]<=1){
			if(a[i]==1) bb++;
		}
		else bb=-1;
		if(aa>=0&&a[i]==1){
			aa++;
		}
		else aa=-1;
	}
	if(aa>=0){
		if(k==1) cout<<aa;
		else {
			aa/=2;
			cout<<aa;
		}
		return 0;
	}
	if(bb>=0){
		if(k==1) cout<<bb;
		else cout<<(bb/2);
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		s[i]=a[i];
		if(a[i]==k){
			if(m)b[m].second=i-1;
			m++;
			if(i+1<n)b[m].first=i+1;
			ans++;
		}
		s[i]=s[i]^s[i-1];
	}
	if(b[m].second==0) b[m].second=n;
	if(m==1) ans=0;
	if(m==n){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=m;i++){
		int r=b[m].second,l=b[m].first;
//		cout<<":::"<<l<<" "<<r<<endl;
		int ll=0,rr=0;
		for(int j=1;j<=n;j++){
			for(int x=l,y=l+j;y<=r,x<=r-j;x++,y++){
				if(x>=ll&&y<=rr) continue;
				if((s[y]^s[x-1])==k){		
//					cout<<x<<" "<<y<<endl;
//					cout<<(s[y]^s[x-1]);cout<<endl; 
					if(x<ll) ll=x;
					if(y>rr) rr=y;
					ans++;
				}
			}
		}
	}
	cout<<ans;
	
	
	
	return 0;
}
/*
4 0 
2 1 0 3
*/
