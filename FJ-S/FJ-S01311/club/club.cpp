#include<bits/stdc++.h>
using namespace std;
int a[110000],b[110000],c[110000];
int ansa[110000],ansb[110000],ansc[110000],x[110000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,ans=0,cnta=0,cntb=0,cntc=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i],&b[i],&c[i]);
			if(a[i]>=b[i] && a[i]>=c[i]){
				ansa[++cnta]=i;
				ans+=a[i];
			}
			else if(b[i]>=a[i] && b[i]>=c[i]){
				ansb[++cntb]=i;
				ans+=b[i];
			}
			else{
				ansc[++cntc]=i;
				ans+=c[i];
			}
		}
		int p=n/2;
		if(cnta>p){
			for(int j=1;j<=cnta;j++){
				x[j]=a[ansa[j]]-max(b[ansa[j]],c[ansa[j]]);
			}
			sort(x+1,x+cnta+1);
			for(int j=1;j<=cnta-p;j++){
				ans-=x[j];
			}
		}
		else if(cntb>p){
			for(int j=1;j<=cntb;j++){
				x[j]=b[ansb[j]]-max(a[ansb[j]],c[ansb[j]]);
			}
			sort(x+1,x+cntb+1);
			for(int j=1;j<=cntb-p;j++){
				ans-=x[j];
			}
		}
		else if(cntc>p){
			for(int j=1;j<=cntc;j++){
				x[j]=c[ansc[j]]-max(a[ansc[j]],b[ansc[j]]);
			}
			sort(x+1,x+cntc+1);
			for(int j=1;j<=cntc-p;j++){
				ans-=x[j];
			}
		}
		cout<<ans<<"\n";
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(x,0,sizeof(x));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
