#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010],sxor[500010],vis[500010],kk[25];
int pre[500010][25];
int cnt1;
void get(int i){
	int t=a[i],p=0;
	while(t){
		++p;
		pre[i][p]=pre[i-1][p]+t%2;
		t/=2;
	}
	for(int j=p+1;j<=20;j++){
		pre[i][j]=pre[i-1][j];
	}
}
void getk(){
	int t=k,p=0;
	while(t){
		kk[++p]=t%2;
		t/=2;
	}
}
bool check1(int l,int r){
	for(int k=l;k<=r;k++){
		if(vis[k]==1) return false;
	}
	return true;
}
bool check2(int r,int l){
	for(int i=1;i<=20;i++){
		if((pre[r][i]-pre[l-1][i])%2!=kk[i]%2) return false;
	}
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	getk();
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt1++;
		get(i);
	}
	if(cnt1==n){
		if(k==0) cout<<n/2<<"\n";
		else if(k==1) cout<<n<<"\n";
		else cout<<0<<"\n";
	}
	else if(n<=1000){
		int ans=0;
		for(int i=1;i<=n;i++){
			sxor[i]=sxor[i-1]^a[i];
		}
		for(int len=1;len<=n;len++){
			for(int i=1;i+len-1<=n;i++){
				if((sxor[i-1]^k)==sxor[i+len-1]){
					if(check1(i,i+len-1)){
						ans++;
						for(int j=i;j<i+len;j++){
							vis[j]=1;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}			
	else{
		int l=1,ans=0;
		for(int r=1;r<=n;r++){
			if(a[r]==k){
				ans++;
				l=r+1;
			}
			else {
				if(check2(r,l)){
					ans++;
					l=r+1;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
