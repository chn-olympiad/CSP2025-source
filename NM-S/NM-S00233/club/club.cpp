#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[100010],aa[100010],bb[100010],cc[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,m,a1=0,b1=0,c1=0,s=0,x,y,a2=1,b2=1,c2=1;
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++){
			x=0,y=0;
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i]){
				a1++;
				s+=a[i];
				x=a[i]-b[i],y=a[i]-c[i];
				if(x>y)swap(x,y);
				aa[a2]=x;
				a2++;
			}
			if(b[i]>a[i]&&b[i]>c[i]){
				b1++;
				s+=b[i];
				x=b[i]-c[i],y=b[i]-a[i];
				if(x>y)swap(x,y);
				bb[b2]=x;
				b2++;
			}
			if(c[i]>a[i]&&c[i]>b[i]){
				c1++;
				s+=c[i];
				x=c[i]-b[i],y=c[i]-a[i];
				if(x>y)swap(x,y);
				cc[c2]=x;
				c2++;
			}
		}
		if(a1<=m&&b1<=m&&c1<=m){
			cout<<s<<endl;
			continue;
		}
		if(a1>m){
			sort(aa+1,aa+a2);
			for(int i=1;i<=a2-m-1;i++){
				s-=aa[i];
			}
		
		}
		if(b1>m){
			sort(bb+1,bb+b2);
			for(int i=1;i<=b2-m-1;i++){
				s-=bb[i];
			}
		
		}
		if(c1>m){
			sort(cc+1,cc+c2);
			for(int i=1;i<=c2-m-1;i++){
				s-=cc[i];
			}
		
		}
		cout<<s<<endl;
	}
	return 0;
}
