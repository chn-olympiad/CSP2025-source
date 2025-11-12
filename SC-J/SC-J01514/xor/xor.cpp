#include<bits/stdc++.h>
using namespace std;
int a[500004],s[5004],c[5004],l[5004];
int xxx(int a,int b){
	int i=1,j=1,ans=0;
	while(a>0){
		if(a%2==0) s[i]=0;
		else s[i]=1;
		i++;
		a/=2;
	}
	while(b>0){
		if(b%2==0) c[j]=0;
		else c[j]=1;
		j++;
		b/=2;
	}
	for(int p=max(i,j)-1;p>=1;p--){
		if(s[p]+c[p]==1) ans=(ans+1)*10;
		else if(s[p]+c[p]==2||s[p]+c[p]==0) ans*=10;
	}
	return ans/10;	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,j=1;
	cin>>n>>k;
	while(k>0){
		if(k%2==0) l[j]=0;
		else l[j]=1;
		j++;
		k/=2;
	}
	k=0;
	for(int i=j;i>=1;i--){
		k=(k+1)*10;
	}
	k/=10;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=2&&k==0){
		if(a[1]==a[2]&&a[1]==0) cout<<2;
		else if(a[1]==a[2]) cout<<1;
		else if(a[1]==0||a[2]==0) cout<<1;
		return 0;
	}else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(xxx(a[i],a[i])==k) cnt++;
		}
		cout<<cnt;
	}
	return 0;
}