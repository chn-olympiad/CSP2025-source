#\
i\
n\
c\
l\
u\
d\
e\
<\
b\
i\
t\
s\
/\
s\
t\
d\
c\
+\
+\
.\
h\
>
#\
d\
e\
f\
i\
n\
e\
 \
a\
k\
i\
o\
i\
 \
r\
e\
t\
u\
r\
n\
 \
0
#define int long long
using namespace std;

struct cge{
	int cz,id;
}c[200001];
const int base=249,mod=998244353998244353;
//const int base=1000,mod=9982443530000000;
map<int,int>mp;
//map<char,int>to;
string s1[200001],s2[200001],t1[200001],t2[200001];
int n,Q,sh1[200001],sh2[200001],tphs1[5000001],tphs2[5000001],len[200001];
int hs[5000001];//,iv[5000001],iv1;
int mul(int a,int b){
	int ans=0;
	while(b){
		if(b%2==1){
			ans+=a;
			ans%=mod;
		}
		a*=2;
		a%=mod;
		b/=2;
	}
	return ans;
}
//int poww(int a,int b){
//	int ans=1;
//	while(b){
//		if(b%2==1){
//			ans*=a;
//			ans%=mod;
//		}
//		a*=a;
//		a%=mod;
//		b/=2;
//	}
//	return ans;
//}
bool cmp(cge x,cge y){
	return x.cz<y.cz;
}

signed main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	freopen("replace4.in","r",stdin);
//	freopen("replace4.out","w",stdout);
	cin>>n>>Q;
	hs[0]=1;
//	iv[0]=1;
//	iv1=poww(base,mod-2);
	for(int i=1;i<=5000000;i++){hs[i]=mul(hs[i-1],base)%mod;}
	bool fg=true;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int tp=s1[i].size();
		bool vsb1=false,vsb2=false;
		for(int j=1;j<=tp;j++){
			if(s1[i][j]!='a'){
				if(s1[i][j]!='b'||vsb1)fg=false;
				else vsb1=true;
			}
			if(s2[i][j]!='a'){
				if(s2[i][j]!='b'||vsb2)fg=false;
				else vsb2=true;
			}
		}
	}
	for(int ii=1;ii<=Q;ii++){
		cin>>t1[ii]>>t2[ii];
		int tp1=t1[ii].size(),tp2=t2[ii].size();
		bool vsb1=false,vsb2=false;
		for(int i=1;i<=tp1;i++){
			if(t1[ii][i]!='a'){
				if(t1[ii][i]!='b'||vsb1)fg=false;
				else vsb1=true;
			}
		}
		for(int i=1;i<=tp2;i++){
			if(t2[ii][i]!='a'){
				if(t2[ii][i]!='b'||vsb2)fg=false;
				else vsb2=true;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(s1[i]==s2[i]){
			n--,i--;
			continue;
		}
		int tp=s1[i].size(),hs1=0,hs2=0;
		len[i]=tp;
		for(int j=0;j<tp;j++){
			hs1=mul(hs1,base);
			hs1+=s1[i][j];
			hs2=mul(hs2,base);
			hs2+=s2[i][j];
			hs1%=mod,hs2%=mod;
		}
		sh1[i]=hs1;
		sh2[i]=hs2;
		int lst=tp-1;
		hs1=0,hs2=0;
		for(int j=tp-1;j>=0;j--){
			if(s1[i][j]!=s2[i][j]){
				lst=j;
				break;
			}
		}
		for(int j=0;j<=lst;j++){
			hs1=mul(hs1,base);
			hs1+=s1[i][j];
			hs2=mul(hs2,base);
			hs2+=s2[i][j];
			hs1%=mod,hs2%=mod;
		}
		c[i].cz=hs1-hs2;
		c[i].id=i;
//		cout<<c[i].cz<<" "<<lst<<" "<<sh1[i]<<" "<<sh2[i]<<"\n";
//		mp[c[i].cz]++;
	}
	sort(c+1,c+n+1,cmp);
	for(int ii=1;ii<=Q;ii++){
		if(t1[ii].size()!=t2[ii].size()){
			cout<<0<<"\n";
			continue;
		}
		int tp=t1[ii].size(),hs1=0,hs2=0,lst=-1;
		for(int j=0;j<tp;j++){
			hs1=mul(hs1,base);
			hs1+=t1[ii][j];
			hs2=mul(hs2,base);
			hs2+=t2[ii][j];
			hs1%=mod,hs2%=mod;
			tphs1[j]=hs1,tphs2[j]=hs2;
		}
		for(int j=tp-1;j>=0;j--){
			if(t1[ii][j]!=t2[ii][j]){
				lst=j;
				break;
			}
		}
		hs1=0,hs2=0;
		for(int j=0;j<=lst;j++){
			hs1=mul(hs1,base);
			hs1+=t1[ii][j];
			hs2=mul(hs2,base);
			hs2+=t2[ii][j];
			hs1%=mod,hs2%=mod;
		}
//		cout<<hs1<<" "<<hs2<<"\n";
		int l=1,r=n,lbg=n+1;
		while(l<=r){
			int mid=(l+r)/2;
			if(c[mid].cz>hs1-hs2){
				r=mid-1;
				lbg=min(lbg,mid);
			}else{
				l=mid+1;
			}
		}
		int ans=0;
		int rt=lbg-1,lt=-1;
		for(int j=rt;j>=1;j--){
			if(c[j].cz==hs1-hs2){
				lt=j;
			}else{
				break;
			}
		}
		if(lt!=-1){
//			cout<<"lt:"<<lt<<" "<<rt<<" "<<ii<<" "<<hs1-hs2<<"\n";
//			for(int i=lt;i<=rt;i++){
//				cout<<c[i].id<<" "<<c[i].cz<<" "<<sh1[c[i].id]<<" "<<len[c[i].id]<<"\n";
//			}
//			for(int i=0;i<tp;i++){
//				cout<<tphs1[i]<<"\n";
//			}
			for(int j=tp-1;j>=0;j--){
//				bool viss=false;
				for(int i=lt;i<=rt;i++){
//					if(j-len[c[i].id]>=0)viss=true;
					if(j-len[c[i].id]>=0&&(tphs1[j]-mul(tphs1[j-len[c[i].id]],hs[len[c[i].id]])%mod+mod)%mod==sh1[c[i].id]&&(tphs2[j]-mul(tphs2[j-len[c[i].id]],hs[len[c[i].id]])%mod+mod)%mod==sh2[c[i].id]){
						ans++;
					}
					if(j-len[c[i].id]==-1&&tphs1[j]==sh1[c[i].id]&&tphs2[j]==sh2[c[i].id]){
						ans++;
					}
//					cout<<"J:"<<j<<" LEN:"<<len[c[i].id]<<" "<<(tphs1[j]-mul(tphs1[j-len[c[i].id]],hs[len[c[i].id]])%mod+mod)%mod<<"\n";
				}
//				if(viss==false)break;
			}
		}
		cout<<ans<<"\n";
//		cout<<mp[hs1-hs2]<<"\n";
	}
	akioi;
}
/*
4 5
a b
cad cbd
aaa aba
bcadd bcbdd
a b
cad cbd
aaa aba
bcadd bcbdd
fhkasbcaddjflkd fhkasbcbddjflkd

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
