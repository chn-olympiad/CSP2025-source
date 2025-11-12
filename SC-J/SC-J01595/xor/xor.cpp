#include<bits/stdc++.h>

#define hyc_qcz_jmr_baoyouwo_AC
#define zty_AK_CSPJ_2025

#define rep(i,s,e) for(int i=s;i<=e;i++)
#define fep(i,s,e) for(int i=s;i<e;i++)
#define per(i,s,e) for(int i=s;i>=e;i--)
#define pef(i,s,e) for(int i=s;i>e;i--)

namespace FastIO{
	template <typename T> inline void read(T &x){
		x=0;
		T f=1;
		T c=getchar();
		for(;!isdigit(c);c=getchar()){
			if(c=='-'){
				f=-1;
			}
		}
		for(;isdigit(c);c=getchar()){
			x=(x<<1)+(x<<3)+(c^48);
		}
		x*=f;
	}
	template <typename T> inline void print(T x){
		if(x<0){
			putchar('-');
			x=-x;
		}
		if(x>9){
			print(x/10);
		}
		putchar((x%10)^48);
	}
}

using namespace std;
using namespace FastIO;
int mp[1048576],n,k,a[500005],now,mxr,ans;
int main(){
	hyc_qcz_jmr_baoyouwo_AC
	zty_AK_CSPJ_2025
//	freopen("xor6.in","r",stdin);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	mp[0]=1;
	read(n);
	read(k);
	rep(i,1,n){
		read(a[i]);
		now^=a[i];
//		cout<<i<<"  "<<(now^k)<<endl;
		if(mp[now^k]>mxr){
			ans++;
			mxr=i;
//			cout<<i<<" "<<ans<<endl;
		}
		mp[now]=i+1;
	}
	print(ans);
	return 0;
}