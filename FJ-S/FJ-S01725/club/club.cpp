#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
int px;
struct peo{
	int a,b,c,k;
}T[100001];
int fd(int i,int k){
	if(k==1) return T[i].a;
	if(k==2) return T[i].b;
	return T[i].c;
}
bool cmp(int l1,int l2){
	return (T[l1].k-fd(l1,px))<(T[l2].k-fd(l2,px));
}
int t,n;
int M[3][100010];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>T[i].a>>T[i].b>>T[i].c;
			if(T[i].a>=T[i].b&&T[i].c<=T[i].a) M[1][++M[1][0]]=i,T[i].k=max(T[i].b,T[i].c),ans+=T[i].a;
			else if(T[i].a<=T[i].b&&T[i].c<=T[i].b) M[2][++M[2][0]]=i,T[i].k=max(T[i].a,T[i].c),ans+=T[i].b;
			else M[3][++M[3][0]]=i,T[i].k=max(T[i].b,T[i].a),ans+=T[i].c;
		}
		if(M[1][0]>n/2||M[2][0]>n/2||M[3][0]>n/2){
			if(M[1][0]>n/2) px=1;
			if(M[2][0]>n/2) px=2;
			if(M[3][0]>n/2) px=3;
			sort(M[px]+1,M[px]+1+M[px][0],cmp);
			for(int i=M[px][0];i>n/2;i--){
				ans-=fd(M[px][i],px);
				ans+=T[M[px][i]].k;
			}
		}
		for(int i=0;i<=n;i++){
			M[1][i]=M[2][i]=M[3][i]=0;
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
