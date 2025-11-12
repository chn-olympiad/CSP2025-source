#include<bits/stdc++.h>
using namespace std;
int n,a[500010],k,aa[500010];
bool dj[500010]={false};
int dq=1,ans=0;
bool pd(int l,int r){
	for(int i=l;i<=r;i++){
		if(dj[i]==true)return false;
	}
	return true;
}
bool pb(int l,int r){
	if(aa[r]^aa[l-1]==k){
		if(pd(l,r)==true){
		for(int i=l;i<=r;i++)dj[i]=true;
		dq=r+1;
		ans++;
		return true;
		}
	}
	return false;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		aa[i]=aa[i-1]^a[i];
//		for(int l=dq;l<=i;l++){
//			for(int r=l;r<=i;r++){
//				pb(l,r);
//			}
//		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j+i<=n;j++){
			int y=j+i;
			if(pb(j,y))break;
		}
	}
	cout<<ans;
} 
