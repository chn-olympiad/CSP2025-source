#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mod1=1000000007,Base1=167;
const int Mod2=1000007243,Base2=1331;
int P1[5000005],P2[5000005];
int len[200005];
int L[200005],R[200005];
int L1[200005],R1[200005];
int L2[200005],R2[200005];
int Ma1[200005],Mb1[200005];
int Ma2[200005],Mb2[200005];
int prea1[200005],prea2[200005];
int preb1[200005],preb2[200005];
char s[3000005],t[3000005];
int n,q; 
void init(){
	P1[0]=P2[0]=1;
	for(int i=1;i<=5000003;i++){
		P1[i]=P1[i-1]*Base1%Mod1;
		P2[i]=P2[i-1]*Base2%Mod2;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	freopen("replace.txt","w",stderr);
	init();
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s>>t;
		int m=strlen(s);
		len[i]=m;
		int mn=m+1,mx=-1;
		for(int j=0;j<m;j++){
			if(s[j]!=t[j]){
				mx=max(mx,j);
				mn=min(mn,j);
			}
		}
		L[i]=mn,R[i]=mx;
		if(mx==-1){
			L1[i]=L2[i]=R1[i]=R2[i]=Ma1[i]=Mb1[i]=Ma2[i]=Mb2[i]=-1;
			continue;
		}
		for(int j=0;j<mn;j++){
			L1[i]=(L1[i]*Base1+s[j])%Mod1;
			L2[i]=(L2[i]*Base2+s[j])%Mod2;
		}
		for(int j=mx+1;j<m;j++){
			R1[i]=(R1[i]*Base1+s[j])%Mod1;
			R2[i]=(R2[i]*Base2+s[j])%Mod2;
		}
		for(int j=mn;j<=mx;j++){
			Ma1[i]=(Ma1[i]*Base1+s[j])%Mod1;
			Ma2[i]=(Ma2[i]*Base2+s[j])%Mod2;
			Mb1[i]=(Mb1[i]*Base1+t[j])%Mod1;
			Mb2[i]=(Mb2[i]*Base2+t[j])%Mod2;
		}
//		if(i==245){
//			cerr<<s[0]<<s[1]<<s[2]<<s[3]<<"\n"; 
//			cerr<<i<<":"<<mn<<" "<<mx<<" "<<Ma1[i]<<" "<<Ma2[i]<<" "<<Mb1[i]<<" "<<Mb2[i]<<"\n";
//			cerr<<i<<":"<<0<<" "<<mn-1<<" "<<mx+1<<" "<<m-1<<" "<<L1[i]<<" "<<L2[i]<<" "<<R1[i]<<" "<<R2[i]<<"\n";
//		}
//		cout<<i<<":"<<mn<<" "<<mx<<" "<<Ma1[i]<<" "<<Ma2[i]<<" "<<Mb1[i]<<" "<<Mb2[i]<<"\n";
	}
	int tttt=0;
	while(q--){
		tttt++;
		cin>>s>>t;
		if(strlen(s)!=strlen(t)){
			cout<<0<<"\n";
			continue;
		}
		int m=strlen(s);
		int mn=m+1,mx=0;
		for(int j=0;j<m;j++){
			if(s[j]!=t[j]){
				mx=max(mx,j+1);
				mn=min(mn,j+1);
			}
		}
		for(int j=1;j<=m;j++){
			prea1[j]=(prea1[j-1]*Base1+s[j-1])%Mod1;
			prea2[j]=(prea2[j-1]*Base2+s[j-1])%Mod2;
			preb1[j]=(preb1[j-1]*Base1+t[j-1])%Mod1;
			preb2[j]=(preb2[j-1]*Base2+t[j-1])%Mod2;
		}
		int S1=(prea1[mx]-prea1[mn-1]*P1[mx-mn+1]%Mod1+Mod1)%Mod1;
		int S2=(prea2[mx]-prea2[mn-1]*P2[mx-mn+1]%Mod2+Mod2)%Mod2;
		int T1=(preb1[mx]-preb1[mn-1]*P1[mx-mn+1]%Mod1+Mod1)%Mod1;
		int T2=(preb2[mx]-preb2[mn-1]*P2[mx-mn+1]%Mod2+Mod2)%Mod2;
//		if(tttt==306){
//			cerr<<tttt<<"!"<<mn<<" "<<mx<<" "<<S1<<" "<<S2<<" "<<T1<<" "<<T2<<"\n";
//		}
		int ans=0;
		for(int j=1;j<=n;j++){
			if(Ma1[j]!=S1||Ma2[j]!=S2||Mb1[j]!=T1||Mb2[j]!=T2){
				continue;
			}
			int ll=mn-L[j],lr=mn-1,rl=mx+1,rr=mx+len[j]-R[j]-1;
			if(ll<=0||rl<=0||lr>m||rr>m){
				continue;
			}
			int ll1=(prea1[lr]-prea1[ll-1]*P1[lr-ll+1]%Mod1+Mod1)%Mod1;
			int rr1=(prea1[rr]-prea1[rl-1]*P1[rr-rl+1]%Mod1+Mod1)%Mod1;
			int ll2=(prea2[lr]-prea2[ll-1]*P2[lr-ll+1]%Mod2+Mod2)%Mod2;
			int rr2=(prea2[rr]-prea2[rl-1]*P2[rr-rl+1]%Mod2+Mod2)%Mod2;
//			if(j==245&&tttt==306){
//				cerr<<tttt<<"!"<<ll<<" "<<lr<<" "<<rl<<" "<<rr<<" "<<ll1<<" "<<ll2<<" "<<rr1<<" "<<rr2<<"\n";
//			}
			if(L1[j]!=ll1||L2[j]!=ll2||R1[j]!=rr1||R2[j]!=rr2){
				continue;
			}
			ans++;
//			if(tttt==306){
//				cerr<<j<<"\n"; 
//			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
这里是T3. 
这不是直接哈希就做完了？ 
好像还没做完，但是差不多了。 
结论1：如果某一个二元组能够构成询问串的某一种替换，那么替换方案是唯一的。 
证明显然。 
这个就有点出生了。 
我有一个想法，我们考虑到询问掌握的信息不多，所以我们处理出询问串不同之处构成的区间；
挂在一个以这个区间的长度，哈希值二元下标处。并处理出询问串的前缀哈希值。 
接下来去模式串，同样找出不同处构成的区间和长度，然后就不可做了。 
止步于此，打nq暴力了。至少有50p。 
是时候结束了，我的OI之旅。 
可惜了这一个好的准考证号啊。 
*/
