#include<bits/stdc++.h>
using namespace std;
const int F=1000;
int a[F],xorr[F];
struct s{
	int s,e;
} aa[1100000];
bool cmp(s a,s b){
	return a.e<b.e;
}
bool can(s a,int l){
	if(l<a.s)
	return 1;
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,kkk;
	cin>>n>>kkk;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xorr[i]=a[i]^xorr[i-1];
	}
	int kk=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(kkk==(xorr[j]^xorr[i-1])){
				aa[kk].s=i;
				aa[kk].e=j;
				kk++;
				//cout<<i<<" "<<j<<" "<<(xorr[j]^xorr[i-1]==kkk)<<" "<<kkk<<"\n";
			}
		}
	}
	sort(aa,aa+kk,cmp);
	int ll=0;
	int tt=0;
	for(int i=0;i<kk;i++){
		if(can(aa[i],ll)){
			ll=aa[i].e;
			tt++;
		}
	}
	cout<<tt;
	//for(int i=0;i<n;i++){
		//int l,r;
		//cin>>l>>r;
		//cout<<(xorr[r]^xorr[l-1]);
	//}
}//     
