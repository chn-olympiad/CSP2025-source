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
int n,num[15];
string s;
int main(){
	hyc_qcz_jmr_baoyouwo_AC
	zty_AK_CSPJ_2025
//	freopen("number4.in","r",stdin);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	fep(i,0,n){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	per(i,9,0){
		rep(j,1,num[i]){
			print(i);
		}
	}
	return 0;
}