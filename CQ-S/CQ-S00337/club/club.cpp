#include<bits/stdc++.h>
using namespace std;
struct club{
	int a1,a2,a3;
}a[100100];
int t,n;
bool cmp(club x,club y){
	return x.a1 >y.a1 ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool b=1,c=1; 
		for(int i=1;i<=n;i++){
			cin>>a[i].a1 >>a[i].a2 >>a[i].a3 ;
			if(a[i].a2 )b=0;
			if(a[i].a3 )c=0;
		}
		if(n==2){
			int m11,m12,m21,m22,k1,k2;
			if(a[1].a1 <=a[1].a2 )
				if(a[1].a2 <=a[1].a3 )m11=a[1].a3 ,m12=a[1].a2 ,k1=3;
				else m11=a[1].a2 ,m12=max(a[1].a1 ,a[1].a3 ),k1=2;
			else
				if(a[1].a1 <=a[1].a3 )m11=a[1].a3 ,m12=a[1].a1 ,k1=3;
				else m11=a[1].a1 ,m12=max(a[1].a2 ,a[1].a3 ),k1=1;
			if(a[2].a1 <=a[2].a2 )
				if(a[2].a2 <=a[2].a3 )m21=a[2].a3 ,m22=a[2].a2 ,k2=3;
				else m21=a[2].a2 ,m22=max(a[2].a1 ,a[2].a3 ),k2=2;
			else
				if(a[2].a1 <=a[2].a3 )m21=a[2].a3 ,m22=a[2].a1 ,k2=3;
				else m21=a[2].a1 ,m22=max(a[2].a2 ,a[2].a3 ),k2=1;
			if(k1!=k2)cout<<m11+m21;
			else cout<<max(m11+m22,m12+m21);
			continue;
		}
		if(b&&c){
			sort(a+1,a+1+n,cmp);
			long long ans;
			for(int i=1;i<=n/2;i++) ans+=a[i].a1 ;
			cout<<ans;
			continue;
		}
	}
	return 0;
}
