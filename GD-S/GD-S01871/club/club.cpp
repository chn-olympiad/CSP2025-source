#include<bits/stdc++.h>
using namespace std;
struct df{
	int ai;
	int bi;
	int ci;
}a[100005];
struct afd{
	int nni;
	int nnt;
}ji[100005];
struct afl{
	int nmi;
	int nmt;
}q[100005];
int ais[100005],bis[100005],cis[100005],asd,b[100005],as,bs,cs,ans,op[100005],k[100005],oq[100005];
int maxn1(int x,int y){
	if(x<=y){
		bis[asd]=1;
		bs++;
		return y;
	}
	if(x>y){
		ais[asd]=1;
		as++;
		return x;
	}
}
int maxn2(int x,int y){
	if(x<=y){
		cis[asd]=1;
		cs++;
		if(ais[asd]=1){
			as--;
			ais[asd]=0;
		}
		if(bis[asd]=1){
			bs--;
			bis[asd]=0;
		}
		return y;
	}
	if(x>y){
		return x;
	}
}
int main(){
	int t,ki[100005],jim=0;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ns=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].ai>>a[i].bi>>a[i].ci;
		}
		for(int i=1;i<=n;i++){
			asd=i;
			b[i]=maxn1(a[i].ai,a[i].bi);
			b[i]=maxn2(b[i],a[i].ci);
		}
		if(as>ns){
			for(int i=1;i<=n;i++){
				if(ais[i]==1){
					jim++;
					ji[jim*2-1].nni=a[i].bi;
					ji[jim*2].nni=a[i].ci;
					ji[jim*2-1].nnt=i;
					ji[jim*2].nnt=i;
					q[jim].nmi=a[i].ai;
					q[jim].nmt=i;
				}
				else{
					ans+=b[i];
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(q[i].nmi<q[j].nmi){
						int mn;
						mn=q[j].nmi;
						q[j].nmi=q[i].nmi;
						q[i].nmi=mn;
					}
				}	
			}
			for(int i=1;i<=n-bs+ns;i++){
				ans+=q[i].nmi;
				oq[q[i].nmt]=1;
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(ji[i].nni<ji[j].nni){
						int mn;
						mn=ji[j].nni;
						ji[j].nni=ji[i].nni;
						ji[i].nni=mn;
					}
				}	
			}
			for(int i=1;i<=as-ns;i++){
				if(oq[q[i].nmt]!=1){
					ans+=ji[i].nni;
					op[ji[i].nnt]=1;
				}
			}
			for(int i=1;i<=n;i++){
				if(op[ji[i].nnt]!=1){
					k[i]=b[ji[i].nnt];
					op[ji[i].nnt]=1;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(k[i]<k[j]){
						int mn;
						mn=k[j];
						k[j]=k[i];
						k[i]=mn;
					}
				}	
			}
			for(int i=1;i<=ns;i++){
				ans+=k[i];
			}
		}
		if(bs>ns){
			for(int i=1;i<=n;i++){
				if(bis[i]==1){
					jim++;
					ji[jim*2-1].nni=a[i].ai;
					ji[jim*2].nni=a[i].ci;
					ji[jim*2-1].nnt=i;
					ji[jim*2].nnt=i;
					q[jim].nmi=a[i].bi;
					q[jim].nmt=i;
				}else{
					ans+=b[i];
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(q[i].nmi<q[j].nmi){
						int mn;
						mn=q[j].nmi;
						q[j].nmi=q[i].nmi;
						q[i].nmi=mn;
					}
				}	
			}
			for(int i=1;i<=n-bs+ns;i++){
				ans+=q[i].nmi;
				oq[q[i].nmt]=1;
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<n;j++){
					if(ji[i].nni<ji[j].nni){
						int mn=ji[j].nni;
						ji[j].nni=ji[i].nni;
						ji[i].nni=mn;
					}
				}	
			}			
			for(int i=1;i<=bs-ns;i++){
				if(oq[q[i].nmt]!=1){
					ans+=ji[i].nni;
					op[ji[i].nnt]=1;
				}
			}
			for(int i=1;i<=n-bs+ns+1;i++){
				if(op[ji[i].nnt]!=1){
					k[i]=b[ji[i].nnt];
					op[ji[i].nnt]=1;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(k[i]<k[j]){
						int mn;
						mn=k[j];
						k[j]=k[i];
						k[i]=mn;
					}
				}	
			}
			for(int i=1;i<=ns;i++){
				ans+=k[i];
			}	
		}
		if(cs>ns){
			for(int i=1;i<=n;i++){
				if(cis[i]==1){
					jim++;
					ji[jim*2-1].nni=a[i].bi;
					ji[jim*2].nni=a[i].ai;
					ji[jim*2-1].nnt=i;
					ji[jim*2].nnt=i;
					q[jim].nmi=a[i].ci;
					q[jim].nmt=i;
				}else{
					ans+=b[i];
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(q[i].nmi<q[j].nmi){
						int mn;
						mn=q[j].nmi;
						q[j].nmi=q[i].nmi;
						q[i].nmi=mn;
					}
				}	
			}
			for(int i=1;i<=n-bs+ns;i++){
				ans+=q[i].nmi;
				oq[q[i].nmt]=1;
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<n;j++){
					if(ji[i].nni<=ji[j].nni){
						int mn=ji[j].nni;
						ji[j].nni=ji[i].nni;
						ji[i].nni=mn;
					}
				}	
			}
			for(int i=1;i<=cs-ns;i++){
				ans+=ji[i].nni;
				op[ji[i].nnt]=1;
			}
			for(int i=1;i<=n;i++){
				if(op[ji[i].nnt]!=1){
					k[i]=b[ji[i].nnt];
					op[ji[i].nnt]=1;
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<n;j++){
					if(k[i]<=k[j]){
						int mn;
						mn=k[j];
						k[j]=k[i];
						k[i]=mn;
					}
				}	
			}
			for(int i=1;i<=ns;i++){
				ans+=k[i];
			}
		}
		if(as<=ns&&bs<=ns&&cs<=ns){
			for(int i=1;i<=n;i++){
				ans+=b[i];
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			ji[i].nni=0;
			ji[i].nnt=0;
			ais[i]=0;
			bis[i]=0;
			cis[i]=0;
			asd=0;
			as=0;
			bs=0;
			cs=0;
			b[i]=0;
			ans=0;
			jim=0;
			a[i].ai=0;
			a[i].bi=0;
			a[i].ci=0;
			k[i]=0;
			q[i].nmi;
			q[i].nmt;
			oq[i]=0;
		}
	}
	return 0;
}
