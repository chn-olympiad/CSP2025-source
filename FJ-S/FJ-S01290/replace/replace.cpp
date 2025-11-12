#include<bits/stdc++.h>
#define LL long long
#define Un unsigned
#define For1(i,a,b) for(i=(a);i<=(b);++i)
#define For2(i,a,b) for(i=(a);i<(b);++i)
#define FoR1(i,a,b) for(i=(a);i>=(b);--i)
#define FoR2(i,a,b) for(i=(a);i>(b);--i)
#define pii std::pair<int,int>
#define mkp std::make_pair
#define pb emplace_back
#define il inline
#define fir first
#define sec second
#define dbg(x...) (fprintf(stderr,x),fflush(stderr))
#define FI using std::cin;std::ios::sync_with_stdio(0),cin.tie(0)
template<class T1>
il void cmin(T1 &x,T1 y){if(x>y)x=y;}
template<class T1>
il void cmax(T1 &x,T1 y){if(x<y)x=y;}
const int Bs=10000/*2333*/,mod[2]={(int)1e9+9,998244853};
il int add(int x,int y,int z){return (x+=y)<mod[z]?x:x-mod[z];}
il void addd(int &x,int y,int z){if((x+=y)>=mod[z])x-=mod[z];}
il int sub(int x,int y,int z){return (x-=y)<0?x+mod[z]:x;}
il void subb(int &x,int y,int z){if((x-=y)<0)x+=mod[z];}
il int mul(int x,int y,int z){return 1ll*x*y%mod[z];}
il void mull(int &x,int y,int z){x=1ll*x*y%mod[z];}
il int pow(int x,int y,int z){int res=1;
	while(y){
		if(y&1)mull(res,x,z);
		mull(x,x,z);
		y>>=1;
	}
	return res;
}
const int L=5001111,N=200111,Q=N;
pii bs[N];
struct Hsh{
	int v0,v1,len;
	Hsh(int v0_=0,int v1_=0,int len_=0){v0=v0_;v1=v1_;len=len_;}
	il Hsh operator+(const int&A)const{
		return Hsh(add(mul(v0,Bs,0),A,0),add(mul(v1,Bs,1),A,1),len+1);
	}
	/*il Hsh operator+(const Hsh&A)const{
		return Hsh()
	}*/
	il Hsh operator-(const Hsh&A)const{
		return Hsh(sub(v0,mul(A.v0,bs[len-A.len].fir,0),0),sub(v1,mul(A.v1,bs[len-A.len].sec,1),1),len-A.len);
	}
	il bool operator==(const Hsh&A)const{
		return v0==A.v0&&v1==A.v1&&len==A.len;
	}
};
Hsh a[N],b[L];
int len[Q];
char tmp1[L],tmp2[L];
int n,q;
signed main(){FI;int i,j,l,t1;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	bs[0]=mkp(1,1);
	For1(i,1,n)bs[i]=mkp(mul(bs[i-1].fir,Bs,0),mul(bs[i-1].sec,Bs,1));
	For1(i,1,n){
		cin>>tmp1+1>>tmp2+1;
		len[i]=strlen(tmp1+1);
		For1(j,1,len[i])a[i]=a[i]+((tmp1[j]-97)*100+tmp2[j]-97);
	}
	For1(i,1,q){
		cin>>tmp1+1>>tmp2+1;
		int len1=strlen(tmp1+1);
		int l_=len1,r_=1;
		For1(j,1,len1){
			b[j]=b[j-1]+((tmp1[j]-97)*100+tmp2[j]-97);
			//dbg("%d %d %d %d %d\n",i,j,b[j].v0,b[j].v1,(b[j]-b[j-1]).v0);
		}
		For1(j,1,len1)if(tmp1[j]!=tmp2[j])r_=j,cmin(l_,j);
		int ans=0;
		For1(j,1,n){

			For1(l,std::max(1,r_-len[j]+1),l_){
				if(l+len[j]-1>len1)break;
				//dbg("a%d|%d %d %d\n",j,a[j].v0,a[j].v1,a[j].len);
				//dbg("b%d[%d,%d]|%d %d %d\n",i,l,l+len[j]-1,(b[l+len[j]-1]-b[l-1]).v0,(b[l+len[j]-1]-b[l-1]).v1,(b[l+len[j]-1]-b[l-1]).len);
				if((b[l+len[j]-1]-b[l-1])==a[j]){/*dbg("OK\n");*/++ans;}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}