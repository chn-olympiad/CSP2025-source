#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int pA,pB,pC;
int sum;
struct Node{
	int a;
	int b;
	int c;
	int fst;
	int mid;
	int lst;
	bool chose;
}k[N];
bool cmp(Node a,Node b){
	if(a.fst!=b.fst)return a.fst>b.fst;
	else if(a.mid !=b.mid)return a.mid>b.mid;
	else return a.lst>b.lst;
}
void solve(){
	sum=0;
	cin>>n;
	memset(k,0,sizeof k);
	for(int i=1;i<=n;i++){
		cin>>k[i].a>>k[i].b>>k[i].c;
		k[i].chose=1;
		k[i].fst=max(k[i].a,max(k[i].b,k[i].c));
		k[i].lst=min(k[i].a,min(k[i].b,k[i].c));
		k[i].mid=(k[i].a+k[i].b+k[i].c)-k[i].fst-k[i].lst;
	}
	sort(k+1,k+n+1,cmp);
	for(int j=1;j<=n;j++){
		if(k[j].fst==k[j].a&&k[j].chose&&pA<=n/2){
			pA++;
			sum+=k[j].a;
			k[j].chose=0;
		}
		if(k[j].fst==k[j].b&&k[j].chose&&pB<=n/2){
			pB++;
			sum+=k[j].b;
			k[j].chose=0;
		}
		if(k[j].fst==k[j].c&&k[j].chose&&pC<=n/2){
			pC++;
			sum+=k[j].c;
			k[j].chose=0;
		}
	}
	for(int j=1;j<=n;j++){
		if(k[j].mid==k[j].a&&k[j].chose&&pA<=n/2){
			pA++;
			sum+=k[j].a;
			k[j].chose=0;
		}
		if(k[j].mid==k[j].b&&k[j].chose&&pB<=n/2){
			pB++;
			sum+=k[j].b;
			k[j].chose=0;
		}
		if(k[j].mid==k[j].c&&k[j].chose&&pC<=n/2){
			pC++;
			sum+=k[j].c;
			k[j].chose=0;
		}
	}
	for(int j=1;j<=n;j++){
		if(k[j].lst==k[j].a&&k[j].chose&&pA<=n/2){
			pA++;
			sum+=k[j].a;
			k[j].chose=0;
		}
		if(k[j].lst==k[j].b&&k[j].chose&&pB<=n/2){
			pB++;
			sum+=k[j].b;
			k[j].chose=0;
		}
		if(k[j].lst==k[j].c&&k[j].chose&&pC<=n/2){
			pC++;
			sum+=k[j].c;
			k[j].chose=0;
		}
	}
	cout<<sum;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--)solve();
	return 0;
}
