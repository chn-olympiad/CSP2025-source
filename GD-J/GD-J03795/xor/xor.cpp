#include<bits/stdc++.h>
using namespace std;
int n;
int k,q[500005],a[500005],s=0,ans;
void solve1(){
	for(int i=1;i<=n;++i){
		for(int j=i-1;j>=s;--j){
			if((q[i]^q[j])==k){
				++ans;
		 		s=i;
				break;
			}
		}
	}
	cout<<ans;
}
void solve2(){
	int ma=0,l=log2(k);
//	cout<<l<<' '; 
	for(int i=1;i<=n;++i){
		ma=max((int)log2(q[i]),ma);
		if(ma<l)continue;
		for(int j=i-1;j>=s;--j){
			if((q[i]^q[j])==k){
				++ans;
		 		s=i;
				break;
			}
		}
	}
	cout<<ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		q[i]= q[i-1]^a[i];
	}
	
//	cout<<endl;
//	for(int i=1;i<=n;++i)cout<<q[i]<<' ';
//	cout<<endl;

	if(n<=2e5)solve1();
	else solve2();
	
//	solve1();
//	solve2();
	return 0;
}
