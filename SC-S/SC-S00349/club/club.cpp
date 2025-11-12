#include<bits/stdc++.h>
using namespace std;
int t;
long long ans;
int shua=0,shub=0,shuc=0;
struct cluba{
	int ai;
	int chaa;
	int lia;
} aa[101011];
struct clubb{
	int bi;
	int chab;
	int lib;
} bb[101011];
struct clubc{
	int ci;
	int lic;
	int chac;
} cc[101011];

bool cmpa(cluba x,cluba y){
	return x.chaa>y.chaa;
}

bool cmpb(clubb x,clubb y){
	return x.chab>y.chab;
}

bool cmpc(clubc x,clubc y){
	return x.chac>y.chac;
}

int dp1[1010101],dp2[1010110],dp3[1010110],a1[1001011],a2[1010101],a3[1101010];
int yia[1010101],yib[1010101],yic[1010101];
int kkka,kkkb,kkkc,ansa,ansb,ansc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(a3,0,sizeof(a3));
		memset(yia,0,sizeof(yia));
		memset(yic,0,sizeof(yic));
		memset(yib,0,sizeof(yib));
		shua=0;
		shub=0;
		shuc=0;
		ansa=0;
		ansb=0;
		ansc=0;
		ans=0; 
		kkka=0;
		kkkb=0;
		kkkc=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a1[i]>=a2[i]&&a1[i]>=a3[i]){
				shua++;	
				int kkkkk=0;
				kkkkk=max(a2[i],a3[i]);
				aa[shua].chaa=a1[i]-kkkkk;
				aa[shua].ai=i;
				if(a3[i]>=a2[i]){
					aa[shua].lia=3;
				}else{
					aa[shua].lia=2;
				}
			}else if(a2[i]>=a1[i]&&a2[i]>=a3[i]){
				shub++;
				int kkkkk=0;
				kkkkk=max(a1[i],a3[i]);
				bb[shub].chab=a2[i]-kkkkk;
				bb[shub].bi=i;
				if(a3[i]>=a1[i]){
					bb[shub].lib=3;
				}else{
					bb[shub].lib=1;
				}
			}else if(a3[i]>=a1[i]&&a3[i]>=a2[i]){
				shuc++;
				int kkkkk=0;
				kkkkk=max(a1[i],a2[i]);
				cc[shuc].chac=a3[i]-kkkkk;
				cc[shuc].ci=i;
				if(a2[i]>=a1[i]){
					cc[shuc].lic=2;
				}else{
					cc[shuc].lic=1;
				}
			}
		}
		if(shua<=n/2&&shub<=n/2&&shuc<=n/2){
			for(int i=1;i<=shua;i++){
				ans+=a1[aa[i].ai];
			}
			for(int i=1;i<=shub;i++){
				ans+=a2[bb[i].bi];
			}
			for(int i=1;i<=shuc;i++){
				ans+=a3[cc[i].ci];
			}
			cout<<ans<<endl;
			continue;
		}	
		if(shua>n/2){
			sort(aa+1,aa+1+shua,cmpa);
			for(int i=(n/2)+1;i<=shua;i++){
				if(aa[i].lia==2){
					ansb+=a2[aa[i].ai];
				}else{
					ansc+=a3[aa[i].ai];
				}	
			}
			for(int i=1;i<=n/2;i++){
				ans+=a1[aa[i].ai];
			}
			for(int i=1;i<=shub;i++){
				ans+=a2[bb[i].bi];
			}
			for(int i=1;i<=shuc;i++){
				ans+=a3[cc[i].ci];
			}
			cout<<ans+ansa+ansb+ansc<<endl;
		}else if(shub>n/2){
			sort(bb+1,bb+1+shub,cmpb);
			for(int i=(n/2)+1;i<=shub;i++){
				if(bb[i].lib==1){
					ansa+=a1[bb[i].bi];
				}else{
					ansc+=a3[bb[i].bi];
				}	
			}
			for(int i=1;i<=shua;i++){
				ans+=a1[aa[i].ai];
			}
			for(int i=1;i<=n/2;i++){
				ans+=a2[bb[i].bi];
			}
			for(int i=1;i<=shuc;i++){
				ans+=a3[cc[i].ci];
			}
			cout<<ans+ansb+ansa+ansc<<endl;
		}else if(shuc>n/2){
			sort(cc+1,cc+1+shuc,cmpc);
			for(int i=(n/2)+1;i<=shuc;i++){
				if(cc[i].lic==1){
					ansa+=a1[cc[i].ci];
				}else{
					ansb+=a2[cc[i].ci];
				}	
			}
			for(int i=1;i<=shua;i++){
				ans+=a1[aa[i].ai];
			}
			for(int i=1;i<=shub;i++){
				ans+=a2[bb[i].bi];
			}
			for(int i=1;i<=n/2;i++){
				ans+=a3[cc[i].ci];
			}
			cout<<ans+ansa+ansb+ansc<<endl;
		} 
	}
	return 0;
}