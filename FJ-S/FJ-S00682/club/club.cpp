#include<bits/stdc++.h>
using namespace std;
int n,t,a[500005][3],b[3],c[3][500005],k;
long long s;
void f(int i){
	for(int l=0;l<=2;l++){
		k=max(a[i][(l+1)%3],a[i][(l+2)%3]);
		if(a[i][l]>=k){
			b[l]++;
			s+=a[i][l];
			c[l][b[l]]=a[i][l]-k;
			return;
		}
	}
}
void h(){
	for(int i=0;i<=2;i++){
		if(b[i]>n/2){
			sort(c[i]+1,c[i]+1+b[i]);
			for(int l=1;l<=b[i]-n/2;l++)s-=c[i][l];
			b[i]=0;
			return;
		}
		b[i]=0;
	}
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		s=0;
		for(int i=1;i<=n;i++)scanf("%i%i%i",&a[i][0],&a[i][1],&a[i][2]),f(i);
		h();
		cout<<s<<'\n';
	}
} 
