#include<bits/stdc++.h>
using namespace std;
int n,q,l[200005];
long long sum1[200005],sum2[200005],sum3[200005],sum4[200005],r1,r2;
const long long p1=1000000637,mod1=1000000931,p2=1000000579,mod2=1000000901;
string a[200005],b[200005],c[200005],d[200005];
long long qpow(long long p,long long pp,long long mod){
	if(pp==0)return 1;
	if(pp==1)return p%mod;
	long long sum=qpow(p,pp>>1,mod);
	if(pp&1)return sum*sum%mod*p%mod;
	return sum*sum%mod;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q,r1=qpow(p1,mod1-2,mod1),r2=qpow(p2,mod2-2,mod2);
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i],l[i]=a[i].size(),a[i]=' '+a[i],b[i]=' '+b[i];
		long long t1=1,t2=1;
		for(int j=1;j<=l[i];++j){
			sum1[i]=(sum1[i]+t1*a[i][j]%mod1)%mod1;
			sum2[i]=(sum2[i]+t2*a[i][j]%mod2)%mod2;
			sum3[i]=(sum3[i]+t1*b[i][j]%mod1)%mod1;
			sum4[i]=(sum4[i]+t2*b[i][j]%mod2)%mod2;
			t1=t1*p1%mod1,t2=t2*p2%mod2;
		}
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		int z=x.size(),f=1,r=z;
		x=' '+x,y=' '+y;
		int cnt=0;
		while(x[f]==y[f])++f;
		while(x[r]==y[r])--r;
		for(int i=1;i<=n;++i){
			int rba=f,lba=r-l[i]+1;
			long long t1=1,t2=1;
			if(lba<=0)lba=1;
			if(lba+l[i]-1>z)continue;
			if(rba<lba)continue;
			long long ans1=0,ans2=0,ans3=0,ans4=0;
			for(int j=lba;j<=lba+l[i]-1;++j){
				ans1=(ans1+t1*x[j]%mod1)%mod1;
				ans2=(ans2+t2*x[j]%mod2)%mod2;
				ans3=(ans3+t1*y[j]%mod1)%mod1;
				ans4=(ans4+t2*y[j]%mod2)%mod2;
				t1=t1*p1%mod1,t2=t2*p2%mod2;
			}
			t1*=r1,t2*=r2,t1%=mod1,t2%=mod2;
			if(ans1==sum1[i]&&ans2==sum2[i]&&ans3==sum3[i]&&ans4==sum4[i]){
				++cnt;
				continue;
			}
			for(int j=lba+1;j<=rba&&j+l[i]-1<=z;++j){
				ans1-=x[j-1],ans2-=x[j-1],ans3-=y[j-1],ans4-=y[j-1];
				ans1+=mod1,ans2+=mod2,ans3+=mod1,ans4+=mod2;
				ans1=ans1*r1%mod1,ans2=ans2*r2%mod2,ans3=ans3*r1%mod1,ans4=ans4*r2%mod2;
				ans1=(ans1+t1*x[j+l[i]-1]%mod1)%mod1;
				ans2=(ans2+t2*x[j+l[i]-1]%mod2)%mod2;
				ans3=(ans3+t1*y[j+l[i]-1]%mod1)%mod1;
				ans4=(ans4+t2*y[j+l[i]-1]%mod2)%mod2;
				if(ans1==sum1[i]&&ans2==sum2[i]&&ans3==sum3[i]&&ans4==sum4[i]){
					++cnt;
					break;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
