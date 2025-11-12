#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
const int N=505;
char s[N];
typedef long long ll;
int n,m;
ll C[502][502];
ll fac[N];
struct node{
	int d,pos;
};
node man[N];
bool cmp(node a,node b){
	return a.d<b.d;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool flag=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) C[i][i]=C[i][0]=1;
	for(int i=1;i<=n;i++) C[i][1]=i;
	for(int i=2;i<=n;i++){
		for(int j=2;j<i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
		}
	}
	fac[1]=1;
	for(int i=2;i<=n;i++) fac[i]=(fac[i-1]*i)%P;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]-'1'!=0) flag=1;
	}
	for(int i=1;i<=n;i++){
		cin>>man[i].d;
		man[i].pos=i;
	}
	sort(man+1,man+n+1,cmp);
	if(!flag){
		cout<<fac[n];
	}
	else{
		if(m==1){
		}
		if(m==n){
			if(flag){
				cout<<0;	
			}
			else{
				cout<<fac[n];
			}
		}
	}
	return 0;
}
