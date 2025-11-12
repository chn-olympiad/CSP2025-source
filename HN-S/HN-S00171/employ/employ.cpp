#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[505],c[505],m,all,b[505],ch[25][25],s[505],p[505];
int64_t f[505][505],ans,d[25];
int chk(int x){
	return x>=mod?x-mod:x;
}
int main(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch,a[i]=(ch=='1'),all+=a[i];
	}
	if(n<=10){
		iota(p+1,p+n+1,1);
		for(int i=1;i<=n;i++)
			cin>>c[i];
		do{
			int cnt=0;
			for(int i=1,cc=0;i<=n;i++){
				if(!a[i]||c[p[i]]<=cc)
					cc++;
				else
					cnt++;
			}
			ans+=(cnt>=m);
		}while(next_permutation(p+1,p+n+1));
		cout<<ans;
		return 0;
	}
	for(int i=1,x;i<=n;i++)
		cin>>x,c[x]++;
	if(all<m)
		return cout<<0,0;
	if(all==n){
		f[0][0]=1;
		for(int o=0,i=0;o<=n;o++)
			for(int p=1;p<=c[o];p++,i++)
				for(int j=0,x;j<=n;j++)
					x=max(j-o+1,0),f[i+1][j+1]=(f[i+1][j+1]+f[i][j]*x)%mod,
					f[i+1][j]=(f[i+1][j]+f[i][j]*(i+1-x))%mod;
		for(int i=0;i<=n-m;i++)
			ans=chk(ans+f[n][i]);
		cout<<ans;
		return 0;
	}
	if(m==1){
		s[0]=c[0];
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+c[i];
		for(int i=0;i<=n;i++)
			if(c[i])
				for(int j=1;j<=n;j++)
					if(a[j]&&i>=j){
						int64_t mul=c[i];
						for(int k=1,cc=0,del=0;k<j;k++){
							if(a[k])
								mul=mul*max(0,s[cc]-(cc>=i)-del)%mod,del++;
							cc++;
						}
						for(int k=1,cc=0;k<=n;k++)
							if(!a[k]||k>j)
								cc++,mul=mul*cc%mod;
						ans=chk(ans+mul);
					}
		cout<<ans;
		return 0;
	}
	if(all<=18){
		for(int i=n;i>=0;i--)
			c[i]+=c[i+1];
		for(int i=0;i<=all;ch[i][0]=1,i++)
			for(int j=1;j<=i;j++)
				ch[i][j]=chk(ch[i-1][j]+ch[i-1][j-1]);
		for(int i=m;i<=all;i++){
			d[i]=1;
			for(int j=m;j<i;j++)
				d[i]=chk(d[i]-d[j]*ch[i][j]%mod+mod);
		}
		for(int s=0;s<1<<all;s++)
			if(__builtin_popcount(s)>=m){
				int tmp=0;
				int64_t mul=1;
				for(int i=1,cc=0;i<=n;i++){
					if(a[i])
						b[i]=(s>>cc&1),cc++;
					if(!b[i])
						tmp++,mul=mul*tmp%mod;
				}
				for(int i=n,cc=0;i>=1;i--){
					if(b[i])
						mul=mul*max(0,c[tmp+1]-cc)%mod,cc++;
					else
						tmp--;
				}
				ans=(ans+mul*d[__builtin_popcount(s)])%mod;
			}
		cout<<ans;
		return 0;
	}
	return 0;
}