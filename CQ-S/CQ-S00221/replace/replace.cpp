#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5000010;
const int M=2e5+10;
char s[N],t[N],r[N];
vector<char>S[M],T[M];
int rt[M],to[N][26],cnt[N],tot,Ha[N];
struct Node{
	int len,ha;
};
vector<Node>G[N];
void insert(int p,int n,Node x){
	for(int i=0;i<n;i++){
		int &q=to[p][r[i]-'a'];
		if(!q)q=++tot;
		p=q;
	}G[p].push_back(x);
}
struct node{
	int ha1,ha2;
	bool operator<(const node &a)const{
		return ha1==a.ha1?ha2<a.ha2:ha1<a.ha1;
	}
}a[M],b[M];
int getid(int ha1,int ha2,int n){
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(a[mid].ha1>=ha1)r=mid;
		else l=mid+1;
	}
	if(a[r].ha1!=ha1)return 0;
	int L=r,R=n;
	while(L<R){
		int mid=(L+R)>>1;
		if(a[mid].ha1>ha1)R=mid-1;
		else if(a[mid].ha2>=ha2)R=mid;
		else L=mid+1;
	}
	if(a[R].ha1!=a[r].ha1||a[R].ha2!=ha2)return 0;
	return R;
}
int L[M],R[M];
const int p1=998244853;
const int p2=1e9+9;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s+1,t+1);
		int m=strlen(s+1),cnp=0;L[i]=1,R[i]=m;
		for(int j=1;j<=m;j++)cnp+=(s[j]==t[j]);
		if(cnp==m)continue;
		while(s[L[i]]==t[L[i]])L[i]++;
		while(s[R[i]]==t[R[i]])R[i]--;
		int ha1=0,ha2=0;
		for(int j=L[i];j<=R[i];j++){
			ha1=((ll)ha1*131%p1+s[j]-'a')%p1;
			ha2=((ll)ha2*131%p2+t[j]-'a')%p2;
		}
		a[i]=b[i]=node{ha1,ha2};
		for(int j=L[i]-1;j>=1;j--)S[i].push_back(s[j]);
		for(int j=R[i]+1;j<=m;j++)T[i].push_back(s[j]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int x=getid(b[i].ha1,b[i].ha2,n);
		if(!rt[x])rt[x]=++tot;
		for(int j=0;j<S[i].size();j++)r[j]=S[i][j];
		int ha=0;
		for(int j=0;j<T[i].size();j++)ha=((ll)ha*233%p1+T[i][j]-'a')%p1; 
		insert(rt[x],S[i].size(),Node{T[i].size(),ha});
	}
	while(q--){
		scanf("%s%s",s+1,t+1);
		int m=strlen(s+1);int l=1,r=m;
		while(s[l]==t[l])l++;
		while(s[r]==t[r])r--;
		int ha1=0,ha2=0;
		for(int j=l;j<=r;j++){
			ha1=((ll)ha1*131%p1+s[j]-'a')%p1;
			ha2=((ll)ha2*131%p2+t[j]-'a')%p2;
		}
		int x=getid(ha1,ha2,n);
		if(!x)puts("0");
		else{
			int p=rt[x],ans=0;
			Ha[0]=0;for(int j=1;j<=m-r;j++)Ha[j]=((ll)Ha[j-1]*233%p1+s[r+j]-'a')%p1;
			for(int j=l;j>=1;j--){
				if(!p)break;
				for(int k=0;k<G[p].size();k++){
					int len=G[p][k].len,ha=G[p][k].ha;
					if(len>m-r)continue;
					ans+=(ha==Ha[len]);
				}
				p=to[p][s[j-1]-'a'];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
