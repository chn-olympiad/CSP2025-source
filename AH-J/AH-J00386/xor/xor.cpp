#include<bits/stdc++.h>
using namespace std;
int a[500005],pre[500005],m1[23],cnt=0,g[23];
int v[22][200005];
struct node{
	int l,r;
}js[2000005];
bool cmp(node a,node b){
	if(a.r!=b.r){
		return a.r<b.r;
	}else{
		return a.l<b.l;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int m2=m;
	int jsm=0;
	while(m2>0){
		jsm++;
		m1[jsm]=m2%2;
		m2/=2;
	}
	int maxn=0,flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(a[i]!=1)flag=1;
	}
	if(flag==0){
		if(m>1){
			cout<<0<<endl;
			return 0;
		}
		if(n%2==1){
			if(m==1){
				cout<<n<<endl;
				
			}
			if(m==0){
				cout<<int(floor(1.0*n/2))<<endl;
			}
		}else{
			if(m==1){
				cout<<n<<endl;
			}
			if(m==0){
				cout<<n/2<<endl;
			}
		}
		return 0;
	}
	else if(flag==1&&maxn<=1){
		if(m>1){
			cout<<0<<endl;
			return 0;
		}else{
			int k=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)k++;
			}
			if(m==1){
				cout<<k<<endl;
			}
			else{
				cout<<k/2<<endl;
			}
		}
		return 0;
	}
	else if(maxn>1){
		for(int i=1;i<=n;i++){
			for(int i=1;i<=21;i++)g[i]=0;
			int k=a[i],zz=0;
			while(k>0){
				zz++;
				g[zz]=k%2;
				k/=2;
			}
			for(int j=1;j<=23;j++){
				v[j][i]=v[j][i-1]+g[j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int flag=1;
				for(int l=1;l<=20;l++){
					int x=v[l][j]-v[l][i-1];
					if(x%2==1&&m1[l]==0){
						flag=0;
						break;
					}
					if(x%2==0&&m1[l]==1){
						flag=0;
						break;
					}
				}
				if(flag==0)continue;
				else {
					js[++cnt].l=i;
					js[cnt].r=j;
				}
			}
		}
		sort(js+1,js+1+cnt,cmp);
		int ans=1,la=js[1].r;
		for(int i=2;i<=cnt;i++){
			if(js[i].l>la){
				ans++;
				la=js[i].r;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
