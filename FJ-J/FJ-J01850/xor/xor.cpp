#include<bits/stdc++.h>
using namespace std;
int n,k,m[10000001];
int as[1000001];
int bs[1000001];
int cs[1000001];
struct bl{
	int lef;
	int rig;
};
bl g[1000001];
bool cmp(bl ac,bl bc){
	return ac.rig <bc.rig ;
}
int yh(int a,int b){
	int anum=0,bnum=0;
	while(a>0){
		as[anum]=a%2;
		a/=2;
		anum++;
	}
	while(b>0){
		bs[bnum]=b%2;
		b/=2;
		bnum++;
	}
	int cnt=0;
	for(int i=0;i<max(anum,bnum);i++){
		if(as[i]==bs[i]){
			cs[i]=0;
		}
		else{
			cs[i]=1;
		}
		cnt+=cs[i]*pow(2,i);
	}
	return cnt;
}
int f(int l,int r){
	int x=0;
	for(int i=l;i<=r;i++){
		x=yh(x,m[i]);
	}
	return x;
}
int main(){
	freopen("xor.in","r","stdin");
	freopen("xor.out","w","stdout");
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f(i,j)==k){
				g[ans].lef =i;
				g[ans].rig =j;
				ans++;
			}
		}
	}
	sort(g,g+ans,cmp);
	int anns=ans;
	int fr=g[0].rig ;
	for(int i=1;i<ans;i++){
		if(fr>g[i].lef ){
			fr=g[i].rig ;
		}
		else{
			anns--;
		}
	}
	cout<<anns;
	return 0;
}
