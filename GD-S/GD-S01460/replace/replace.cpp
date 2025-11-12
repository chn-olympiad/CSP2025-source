#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e5+10;
ll n,q,ans,len,l[maxn];
string s[maxn][3],t1,t2;
void work2(string ns){
	string tmp=ns;
	for(int i=1;i<=n;i++){
		for(int j=0;j+l[i]<=len;j++){
			ll pos=j;
			bool flg=1;
			for(int k=0;k<l[i];k++){
				flg&=(tmp[j+k]==s[i][1][k]);
				if(!flg)break;
			}if(flg){
				for(int k=0;k<l[i];k++){
					tmp[j+k]=s[i][2][k];
				}
			}if(tmp==t2)ans++;
			tmp=ns;
		}
	}
}ll flg1=1;
pair<ll,ll>a[maxn];
ll pos[maxn][3],d[maxn];
void work1(){
	ll pos1=0,pos2=0;
	for(int i=0;i<len;i++){
		if(t1[i]=='b')pos1=i;
		if(t2[i]=='b')pos2=i;
	}for(int i=1;i<=n;i++){
		if(pos1>=a[i].first&&pos1<len-a[i].second){
			if(pos1+d[i]==pos2)ans++;
		}
	}
}
void solve(){
	cin>>t1>>t2;
	len=t1.length();//cout<<flg1<<' ';
	for(int i=0;i<len;i++){
		flg1&=(t1[i]=='a'||t1[i]=='b');
		flg1&=(t2[i]=='a'||t2[i]=='b');
	}ans=0;
	
	if(flg1){
		work1();
		cout<<ans<<endl;
		return ;
	}
	
//	dfs(t1);
	work2(t1);
	cout<<ans<<endl;
}
int main(){
//	freopen("replace4.in","r",stdin);
//	freopen("replace4.out","w",stdout);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		l[i]=s[i][1].length();
		for(int j=0;j<l[i];j++){
			if(s[i][1][j]=='b'){
				pos[i][1]=j;
				a[i]=make_pair(j,l[i]-j-1);
			}if(s[i][2][j]=='b'){
				pos[i][2]=j;
			}
			flg1&=(s[i][1][j]=='a'||s[i][1][j]=='b');
			flg1&=(s[i][2][j]=='a'||s[i][2][j]=='b');
		}d[i]=pos[i][2]-pos[i][1];
	}while(q--)solve();
	return 0;
} 
