#include <bits/stdc++.h>
using namespace std;
const long long p=998244853,bas=91;
int n,q;
long long has[3][200010],d[200010],t[200010],pw[2000010],th[3][2000010];
vector<char> c[3][200010];
char ch[2000010],s[3][2000010];
long long qpow(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
void pre(int x){
	for(int i=0;i<2;i++){
		for(int j=0;j<c[i][x].size();j++) has[i][x]=(has[i][x]*bas+c[i][x][j]-'a'+1)%p;
	}
	//cout<<has[0][x]<<' '<<has[1][x]<<endl;
	long long res=0;
	for(int i=0;i<c[0][x].size();i++){
		if(c[0][x][i]!=c[1][x][i]){
			if(!d[x]) t[x]=i;
			res=(res*bas+c[1][x][i]-'a'+1)%p;
			d[x]=res;
		}else if(res) res=(res*bas+27)%p;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;pw[0]=1;
	for(int i=1;i<=2000000;i++) pw[i]=pw[i-1]*bas%p;
	for(int i=1;i<=n;i++){
		scanf("%s",ch);
		int len=strlen(ch);
		for(int j=0;j<len;j++) c[0][i].push_back(ch[j]);
		scanf("%s",ch);
		for(int j=0;j<len;j++) c[1][i].push_back(ch[j]);
		pre(i);
	}
	while(q--){
		scanf("%s%s",s[0]+1,s[1]+1);
		int len=strlen(s[0]+1),ans=0;
		long long tmp=0,res=0,tag=0;
		for(int i=0;i<2;i++){
			for(int j=1;j<=len;j++){
				th[i][j]=(th[i][j-1]*bas+s[i][j]-'a'+1)%p;
			}
		}
		//cout<<th[0][len]<<' '<<th[1][len]<<endl;
		for(int i=1;i<=len;i++){
			if(s[0][i]!=s[1][i]){
				if(!tmp) tag=i;
				res=(res*bas+s[1][i]-'a'+1)%p;
				tmp=res;
			}else if(res) res=(res*bas+27)%p;
		}
		for(int i=1;i<=n;i++){
			if(tmp==d[i]){
				int st=tag-t[i],ed=st+c[0][i].size()-1;
				if(st<=0||ed>len) continue ;
				//cout<<ans<<' '<<st<<' '<<ed<<endl;
				if((th[0][ed]-th[0][st-1]*pw[ed-st+1]%p+p)%p==has[0][i]&&(th[1][ed]-th[1][st-1]*pw[ed-st+1]%p+p)%p==has[1][i]) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

