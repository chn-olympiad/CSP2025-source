//GZ-S00033 华东师范大学附属贵阳学校 侯易辰 
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		int n,a[100001],b[100001],c[100001];
		cin>>n;
		int falg1=0,falg2=0;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]==0) falg1==1;
			if(c[i]==0) falg2==1;
		}
		if(falg1==0&&falg2==0){
			int ans=0;
			for(int i=n-1;i>=n/2;i--) ans+=a[i];
			cout<<ans<<endl;
		}
		else if(n==2){
			int ans=max(max(a[0]+b[1],a[0]+c[1]),max(max(b[0]+a[1],b[0]+c[1]),max(c[0]+a[1],c[0]+b[1])));
			cout<<ans;
		}
		else{
			int y=a[0]+a[1],q=b[0]+b[1],l=c[0]+c[1],d=a[0]+b[1],e=a[0]+c[1],f=b[0]+a[1],g=b[0]+c[1],h=c[0]+a[1],i=c[0]+b[1];
			y+=max(max(b[2]+b[3],b[2]+c[3]),max(c[2]+b[3],c[2]+c[3]));
			q+=max(max(a[2]+a[3],a[2]+c[3]),max(c[2]+a[3],c[2]+c[3]));
			l+=max(max(a[2]+a[3],a[2]+b[3]),max(b[2]+a[3],b[2]+b[3]));
			d+=max(max(max(a[2]+b[3],a[2]+c[3]),max(b[2]+a[3],b[2]+c[3])),max(max(c[2]+c[3],c[2]+a[3]),c[2]+b[3]));
			f+=max(max(max(a[2]+b[3],a[2]+c[3]),max(b[2]+a[3],b[2]+c[3])),max(max(c[2]+c[3],c[2]+a[3]),c[2]+b[3]));
			e+=max(max(max(a[2]+b[3],a[2]+c[3]),max(b[2]+a[3],b[2]+c[3])),max(max(c[2]+b[3],c[2]+a[3]),b[2]+b[3]));
			h+=max(max(max(a[2]+b[3],a[2]+c[3]),max(b[2]+a[3],b[2]+c[3])),max(max(c[2]+b[3],c[2]+a[3]),b[2]+b[3]));
			g+=max(max(max(a[2]+b[3],a[2]+c[3]),max(b[2]+a[3],b[2]+c[3])),max(max(c[2]+b[3],a[2]+a[3]),c[2]+a[3]));
			i+=max(max(max(a[2]+b[3],a[2]+c[3]),max(b[2]+a[3],b[2]+c[3])),max(max(c[2]+b[3],a[2]+a[3]),c[2]+a[3])); 
			cout<<max(max(max(y,q),max(l,d)),max(max(max(f,e),max(h,g)),i));
		} 
	}
	return 0;
}
