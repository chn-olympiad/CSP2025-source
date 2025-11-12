#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,q,ct,l,r;
string a[200007],b[200007],c,d,e;
ll bas[3]={37,1331,0x66ccff};
ll mod[3]={1000000007,1000000009,998244353};
ll ha[3][200007],hb[3][200007],hc[3][5000007],hd[3][5000007];
ll qp(int p,ll x){
	ll tmp=bas[p],ans=1;
	for(int i=0;i<30;i++){
		if(x&(1<<i)) ans=(ans*tmp)%mod[p];
		tmp=(tmp*tmp)%mod[p];
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	srand(time(0));
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i].size();j++){
			for(int p=0;p<3;p++) ha[p][i]=(ha[p][i]+qp(p,j)*a[i][j-1])%mod[p];
		}
		for(int j=1;j<=b[i].size();j++){
			for(int p=0;p<3;p++) hb[p][i]=(hb[p][i]+qp(p,j)*b[i][j-1])%mod[p];
		}
	}
	while(m--){
		cin>>c>>d;
		int s=0;
		if(c.size()!=d.size()){
			cout<<0<<endl;
			continue;
		}
		l=r=-1;
		for(int i=0;i<c.size();i++){
			if(c[i]!=d[i]){
				r=i;
				if(l==-1) l=i;
			}
		} 
		for(int p=0;p<3;p++) hc[p][0]=0;
		for(int j=1;j<=c.size();j++){
			for(int p=0;p<3;p++) hc[p][j]=(hc[p][j-1]+qp(p,j)*c[j-1])%mod[p];
		}
		for(int j=1;j<=d.size();j++){
			for(int p=0;p<3;p++) hd[p][j]=(hd[p][j-1]+qp(p,j)*d[j-1])%mod[p];
		}
		for(int i=1;i<=n;i++){
			int u=c.size(),v=a[i].size();
			if(u<v) continue;
			for(int j=0;j<=u-v;j++){
				int f=1;
				//cout<<i<<' '<<hb[0][i]<<' '<<hb[0][i]*qp(0,j)%mod[0]<<' '<<j<<' '<<hd[0][j+v]<<' '<<(hd[0][j+v]-hd[0][j]+mod[0])%mod[0]<<' '<<qp(0,j)<<endl;
				for(int p=0;p<3;p++) if(ha[p][i]*qp(p,j)%mod[p]!=(hc[p][j+v]-hc[p][j]+mod[p])%mod[p]) f=0;
				for(int p=0;p<3;p++) if(hb[p][i]*qp(p,j)%mod[p]!=(hd[p][j+v]-hd[p][j]+mod[p])%mod[p]) f=0;
				//cout<<l<<' '<<r<<' '<<i<<' '<<j+1<<' '<<j+v<<endl;
				if(f){
					//cout<<i<<' '<<j+1<<' '<<j+v<<endl;
					for(int k=1;k<=20;k++){
						int p=rand()%u;
						if(p>=j&&p<j+v) continue;
						if(c[p]!=d[p]){
							f=0;
							break;
						}
					}
					if(f){
						s++;
						break;	
					}
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
