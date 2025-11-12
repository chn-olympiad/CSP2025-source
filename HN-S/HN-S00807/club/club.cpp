#include<bits/stdc++.h>
using namespace std;
struct zz{
	int n,i;
};
zz a[100001],b[100001],c[100001];
int gcd(zz a,zz b){
	if(a.n>b.n) return 0;
	else return 1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int f=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].n>>b[i].n>>c[i].n;
			a[i].i=i,b[i].i=i,c[i].i=i;
		} 
		sort(a+1,a+n+1,gcd);
		int s=0,a1=0,b1=0,c1=0;
		for(int i=1;i<=n;i++){
			if(a1<n/2){
				if(b[a[i].i].n>a[i].n&&b1<n/2){
					s+=b[a[i].i].n;	
					b1++;
				}else if(c[a[i].i].n>a[i].n&&c1<n/2){
					s+=c[a[i].i].n;
					c1++;
				}else{
					s+=a[a[i].i].n;	
					a1++;
				} 
			}else{
				if(b[a[i].i].n>b[a[i].i].n&&b1<n/2){
					s+=b[a[i].i].n;	
					b1++;
				}else{
					s+=c[a[i].i].n;
					c1++;
				}
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
