#include <bits/stdc++.h>
using namespace std;
int t,z[100010];
int cmp(int a,int b){
	return a>b;
}
int m(int n){
	bool l;
	for(int i=1;i<=n;i++){
		if(n==z[i])l=0;
	}
	return l;
}
int main(){	
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);	
	cin>>t;
	while(t--){
		int n,sum=0;
		cin>>n;
		int a[100010];
		int b[100010];
		int c[100010];
		int a1=1,b1=1,c1=1,a2=0,b2=0,c2=0,z1=1,q=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			a[i]=a[i]*10+i;
			cin>>b[i];
			b[i]=b[i]*10+i;
			cin>>c[i];
			c[i]=c[i]*10+i;
			
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		
		
		
		
		while(q==n){
			if(a[a1]==max(a[a1],max(b[b1],c[c1]))&&m(a[a1]%10)&&a2<=n/2&&a1!=0){
				a2++;
				a1++;
				sum+=max(a[a1],max(b[b1],c[c1]))/10;
				z[z1]=a[a1]%10;
				z1++;
				q++;
			}
			else if(b[b1]==max(a[a1],max(b[b1],c[c1]))&&m(b[b1]%10)&&b2<=n/2&&b1!=0){
				b2++;
				b1++;
				sum+=max(a[a1],max(b[b1],c[c1]))/10;
				z[z1]=b[b1]%10;
				z1++;
				q++;
			}
			else if(m(c[c1]%10)&&c2<=n/2&&c1!=0){
				c2++;
				c1++;
				sum+=max(a[a1],max(b[b1],c[c1]))/10;
				z[z1]=c[c1]%10;
				z1++;
				q++;
			}
		}
		cout<<sum;
	}
	return 0;
}
