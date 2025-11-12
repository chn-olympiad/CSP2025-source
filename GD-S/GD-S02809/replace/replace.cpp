#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int mod1=998244353,mod2=1e9+7;
const int B=137,D=5000001;
int n,q;
int pw1[5000005],pw2[5000005],inv1[5000005],inv2[5000005];
vector<char>s1[200005],s2[200005],t1[200005],t2[200005];
vector<pair<int,int> >hsh1[200005],hsh2[200005],hsh3[200005],hsh4[200005];
char s[5000005];
vector<pair<int,int> >vec[600];
vector<pair<int,int> >val[10000005];

int qpow(int a,int b,int mod){
	int ans=1,base=a;
	while(b){
		if(b&1){
			ans=1ll*ans*base%mod;
		}
		base=1ll*base*base%mod;
		b/=2;
	}
	return ans;
}

void slv(){
	for(int i=1;i<=n;i++){
		int len=s1[i].size();
		int id=0;
		for(int j=0;j<len;j++){
			if(s1[i][j]=='b'){
				id=j;
				break;
			}
		}
		int id2=0;
		for(int j=0;j<len;j++){
			if(s2[i][j]=='b'){
				id2=j;
				break;
			}
		}
		val[id-id2+D].push_back(make_pair(i,id));
	}
	for(int i=1;i<=q;i++){
		int res=0;
		int len=t1[i].size();
		int id=0;
		for(int j=0;j<len;j++){
			if(t1[i][j]=='b'){
				id=j;
				break;
			}
		}
		int id2=0;
		for(int j=0;j<len;j++){
			if(t2[i][j]=='b'){
				id2=j;
				break;
			}
		}
		int d=id-id2+D;
		int L2=val[d].size();
		//cout<<L2<<endl;
		for(int j=0;j<L2;j++){
			int tmp1=val[d][j].first,tmp2=val[d][j].second;
		//	cout<<tmp1<<" "<<id<<" "<<len<<endl;
			if(tmp2>id){
				continue;
			}
			if((s1[tmp1].size()-tmp2)>(len-id)){
				continue;
			}
			res++;
		}
		printf("%d\n",res);
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	bool FL=1;
	int SS1=0,SS2=0;
	scanf("%d%d",&n,&q);
	pw1[0]=1;pw2[0]=1;inv1[0]=1,inv2[0]=1;
	for(int i=1;i<=5000000;i++){
		pw1[i]=1ll*pw1[i-1]*B%mod1;
		pw2[i]=1ll*pw2[i-1]*B%mod2;
	}
	int i1=qpow(B,mod1-2,mod1);
	int i2=qpow(B,mod2-2,mod2);
	for(int i=1;i<=5000000;i++){
		inv1[i]=1ll*inv1[i-1]*i1%mod1;
		inv2[i]=1ll*inv2[i-1]*i2%mod2;
	}
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		int len=strlen(s+1);
		long long sum1=0,sum2=0;
		for(int j=1;j<=len;j++){
			s1[i].push_back(s[j]);
			if(s[j]=='a')SS1++;
			else if(s[j]=='b')SS2++;
			sum1=sum1+1ll*((int)s[j])*pw1[j-1]%mod1;sum1%=mod1;
			sum2=sum2+1ll*((int)s[j])*pw2[j-1]%mod2;sum2%=mod2;
			hsh1[i].push_back(make_pair(sum1,sum2));
		}
		if(SS1!=len-1||SS2!=1){
			FL=0;
		}
		SS1=SS2=0;
		sum1=0,sum2=0;
		scanf("%s",s+1);
		for(int j=1;j<=len;j++){
			s2[i].push_back(s[j]);
			if(s[j]=='a')SS1++;
			else if(s[j]=='b')SS2++;
			sum1=sum1+1ll*((int)s[j])*pw1[j-1]%mod1;sum1%=mod1;
			sum2=sum2+1ll*((int)s[j])*pw2[j-1]%mod2;sum2%=mod2;
			hsh2[i].push_back(make_pair(sum1,sum2));
		} 
		if(SS1!=len-1||SS2!=1){
			FL=0;
		}
		SS1=SS2=0;
	}
	for(int i=1;i<=q;i++){
		scanf("%s",s+1);
		int len=strlen(s+1);
		long long sum1=0,sum2=0;
		for(int j=1;j<=len;j++){
			t1[i].push_back(s[j]);
			if(s[j]=='a')SS1++;
			else if(s[j]=='b')SS2++;
			sum1=sum1+1ll*((int)s[j])*pw1[j-1]%mod1;sum1%=mod1;
			sum2=sum2+1ll*((int)s[j])*pw2[j-1]%mod2;sum2%=mod2;
			hsh3[i].push_back(make_pair(sum1,sum2));
		}
		if(SS1!=len-1||SS2!=1){
			FL=0;
		}
		SS1=SS2=0;
		scanf("%s",s+1);
		sum1=0,sum2=0;
		for(int j=1;j<=len;j++){
			t2[i].push_back(s[j]);
			if(s[j]=='a')SS1++;
			else if(s[j]=='b')SS2++;
			sum1=sum1+1ll*((int)s[j])*pw1[j-1]%mod1;sum1%=mod1;
			sum2=sum2+1ll*((int)s[j])*pw2[j-1]%mod2;sum2%=mod2;
			hsh4[i].push_back(make_pair(sum1,sum2));
		}
		if(SS1!=len-1||SS2!=1){
			FL=0;
		}
		SS1=SS2=0;
	}
	if(FL==1){
		slv();
		return 0;
	}
	for(int i=1;i<=n;i++){
		int len=s1[i].size();
		for(int j=0;j<len;j++){
			int x=(int)s1[i][j],y=(int)s2[i][j];
			x--,y--;
			int z=x*26+y;
			vec[z].push_back(make_pair(i,j));
		}
	}
	for(int i=1;i<=q;i++){
		int res=0;
		int len=t1[i].size();
		int id=-1,x,y,z;
		for(int j=0;j<len;j++){
			if(t1[i][j]!=t2[i][j]){
				id=j;
				x=(int)t1[i][j],y=(int)t2[i][j];
				x--,y--;
				z=x*26+y;
				break;
			}
		}
		int id2=-1;
		for(int j=len-1;j>=0;j--){
			if(t1[i][j]!=t2[i][j]){
				id2=j;
				break;
			}
		}
		len=vec[z].size();
		int Len1=t1[i].size();
		for(int j=0;j<len;j++){
			int tmp1=vec[z][j].first,tmp2=vec[z][j].second;
			
			int L=s1[tmp1].size();
			int l=id-tmp2;
			int r=l+L-1;
		//	cout<<tmp1<<" "<<tmp2<<" "<<L<<" "<<l<<" "<<r<<endl;
			if(l<0){
				continue;
			}
			if(r<id2||r>=Len1){
				continue;
			}
			int h1=hsh1[tmp1][L-1].first,h2=hsh1[tmp1][L-1].second;
			int h3=1ll*(hsh3[i][r].first-(l==0?0:hsh3[i][l-1].first))*inv1[l]%mod1;
			int h4=1ll*(hsh3[i][r].second-(l==0?0:hsh3[i][l-1].second))*inv2[l]%mod2;
			h3=(h3%mod1+mod1)%mod1;
			h4=(h4%mod2+mod2)%mod2;
			if(h1!=h3||h2!=h4)continue;
			
			h1=hsh2[tmp1][L-1].first,h2=hsh2[tmp1][L-1].second;
			h3=1ll*(hsh4[i][r].first-(l==0?0:hsh4[i][l-1].first))*inv1[l]%mod1;
			h4=1ll*(hsh4[i][r].second-(l==0?0:hsh4[i][l-1].second))*inv2[l]%mod2;
			h3=(h3%mod1+mod1)%mod1;
			h4=(h4%mod2+mod2)%mod2;
			if(h1!=h3||h2!=h4)continue;
			res++;
		}
		printf("%d\n",res);
	}
	return 0;
}
