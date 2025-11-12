//调了一年，红温了； 

#include<bits/stdc++.h>
#define int long long
using namespace std;

int T,n;

struct e{
	int a,b,c;
}a[100001],b[100001],c[100001];

int ans,aa,bb,cc,ans1,ans2;

bool cmp1(e x,e y){
	return x.b>y.b;
}
bool cmp2(e x,e y){
	return x.c>y.c;
}

int f[100001],f1[100001];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	
	
	while(T--){
		cin>>n;
		aa=0,bb=0,cc=0;
		ans=0;
		memset(f,0,sizeof(f));
		memset(f1,0,sizeof(f1));
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
//			f[n]+=a[i].a;
//			b[i]=a[i].b-a[i].a;
//			c[i]=a[i].c-a[i].a;
//			
//			cout<<b[i]<<' '<<c[i]<<endl;
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
				aa++;
				ans+=a[i].a;
				f1[i]=1;
			}
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
				bb++;
				ans+=a[i].b;
				f1[i]=2;
			}
			else if(a[i].c>=a[i].b&&a[i].c>=a[i].a){
				cc++;
				ans+=a[i].c;
				f1[i]=3;
			}
			
		}
		ans2=0;
		if(aa>n/2){
			for(int i=1;i<=n;i++){
				if(f1[i]!=1)continue;
				ans2++;
				b[ans2].a=c[ans2].a=i;
				b[ans2].b=c[ans2].b=a[i].b-a[i].a;
				b[ans2].c=c[ans2].c=a[i].c-a[i].a;
			}
			ans1=aa;
		}
		else if(bb>n/2){
			for(int i=1;i<=n;i++){
				if(f1[i]!=2)continue;
				ans2++;
				b[ans2].a=c[ans2].a=i;
				b[ans2].b=c[ans2].b=a[i].a-a[i].b;
				b[ans2].c=c[ans2].c=a[i].c-a[i].b;
			}
			ans1=bb;
		}
		else if(cc>n/2){
			for(int i=1;i<=n;i++){
				if(f1[i]!=3)continue;
				//cout<<i<<' '<<a[i].a<<' '<<a[i].b<<' '<<a[i].c<<endl;
				ans2++;
				b[ans2].a=c[ans2].a=i;
				b[ans2].b=c[ans2].b=a[i].a-a[i].c;
				b[ans2].c=c[ans2].c=a[i].b-a[i].c;
			}
			ans1=cc;
		}
		else {
			cout<<ans<<endl;
			continue;
		}
//		cout<<ans2<<endl;
//		for(int i=1;i<=ans2;i++){
//			cout<<b[i].b<<' '<<c[i].c<<' '<<b[i].a<<endl;
//		}
		sort(b+1,b+ans2+1,cmp1);
		sort(c+1,c+ans2+1,cmp2);
//		cout<<ans2<<endl;
//		for(int i=1;i<=ans2;i++){
//			cout<<b[i].b<<' '<<c[i].c<<endl;
//		}
		
		int cx=1,xc=1;
		
		while(1){
			if(ans1==n/2){
				break;
			}
			//cout<<ans1<<' '<<ans<<' '<<b[cx].b<<' '<<b[cx].a<<' '<<c[xc].c<<' '<<c[xc].a<<endl;
			if(b[cx].b>=c[xc].c){
				f[b[cx].a]=1;
				//cout<<ans<<' '<<b[cx].b<<' '<<cx<<endl;
				ans+=b[cx].b;
				
				while(1){
					cx++;
					if(f[b[cx].a]==0)break;
				}
				
				while(1){
					xc++;
					if(f[c[xc].c]==0)break;
				}
				
			}
			else {
				f[c[xc].a]=1;
				//cout<<ans<<' '<<c[xc].c<<' '<<xc<<endl;
				ans+=c[xc].c;
				
				while(1){
					cx++;
					if(f[b[cx].a]==0)break;
				}
				
				while(1){
					xc++;
					if(f[c[xc].c]==0)break;
				}
			}
			ans1--;	
		}
		
		cout<<ans<<endl;
		//cout<<f[n]<<endl;
	}
} 

/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
