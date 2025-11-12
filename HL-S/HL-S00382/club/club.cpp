#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		int n;
		scanf("%lld",&n);
		int a1[n+10],a2[n+10],a3[n+10],cha,z1[N]={},z2[N]={},z3[N]={},h[3]={},maxx;
		h[1]=1;
		h[2]=1;
		h[3]=1;
		long long k=0,max1,max2;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a1[i],&a2[i],&a3[i]);
			max1=max(a1[i],a2[i]);
			max2=max(a2[i],a3[i]);
			maxx=max(max1,max2);
			if(a1[i]==maxx){
				max2=max(a2[i],a3[i]);
			}
			else if(a2[i]==maxx){
				max2=max(a1[i],a3[i]);
			}
			else if(a3[i]==maxx){
				max2=max(a2[i],a1[i]);
			}
			cha=maxx-max2;
			if(a1[i]==maxx&&h[1]-1!=n/2){
				k+=maxx;
				z1[h[1]]=cha;
				h[1]++;
				if(h[2]-1!=n/2&&h[3]-1!=n/2) sort(z1+1,z1+h[1]);
			}
			else if(a2[i]==maxx&&h[2]-1!=n/2){
				k+=maxx;
				z2[h[2]]=cha;
				h[2]++;
				if(h[1]-1!=n/2&&h[3]-1!=n/2) sort(z2+1,z2+h[2]);
			}
			else if(a3[i]==maxx&&h[3]-1!=n/2){
				k+=maxx;
				z3[h[3]]=cha;
				h[3]++;
				if(h[1]-1!=n/2&&h[2]-1!=n/2) sort(z3+1,z3+h[3]);
			}
			else if(a1[i]==maxx&&h[1]-1==n/2&&cha>z1[1]){
				k=k+maxx-z1[1];
				z1[1]=cha;
				sort(z1+1,z1+h[1]);
			}
			else if(a2[i]==maxx&&h[2]-1==n/2&&cha>z2[1]){
				k=k+maxx-z2[1];
				z2[1]=cha;
				sort(z2+1,z2+h[2]);
			}
			else if(a3[i]==maxx&&h[3]-1==n/2&&cha>z3[1]){
				k=k+maxx-z3[1];
				z3[1]=cha;
				sort(z3+1,z3+h[3]);
			}
			else if(a1[i]==maxx&&h[1]-1==n/2){
				k=k+maxx-cha;
			}
			else if(a2[i]==maxx&&h[2]-1==n/2){
				k=k+maxx-cha;
			}
			else if(a3[i]==maxx&&h[3]-1==n/2){
				k=k+maxx-cha;
			}
		}
		cout << k << '\n';
	}
}
