#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int b1[N],b2[N],b3[N],zzz1[N],zzz[N];
struct ac{
	long long bm,lk;
}zx[N],qc[N];
int t,n,lik=0,bm1,bm2,bm3,pjz=n>>1;
struct jd{
	int nam,bm;
}ql[N];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int i=0;i<t;i++){
		cin >> n;
		for (int i=1;i<=n;i++){
			cin >> b1[i];
			cin >> b2[i];
			cin >> b2[i];
		}
		for(int i=1;i<=n;i++){
			int bm1,bm2,bm3,z=n>>1;
			if(b1[i]>b2[i] &&b1[i]>b3[i]){
				zx[i].lk=b1[i];
				zx[i].bm=1;
			}else if(b2[i]>b1[i] &&b2[i]>b3[i]){
				zx[i].lk=b2[i];
				zx[i].bm=2;
			}else if(b3[i]>b2[i] &&b3[i]>b1[i]){
				zx[i].lk=b3[i];
				zx[i].bm=3;
				
			if(b1[i]>b2[i] &&b3[i]>b1[i] || b1[i]>b3[i] &&b2[i]>b1[i]){
				qc[i].lk=b1[i];
				qc[i].bm=1;
			}else if(b2[i]>b3[i] &&b1[i]>b2[i] || b2[i]>b1[i] &&b3[i]>b2[i]){
				qc[i].lk=b2[i];
				qc[i].bm=2;
			}else if(b3[i]>b1[i] &&b2[i]>b3[i] || b3[i]>b2[i] &&b1[i]>b3[i]){
				qc[i].lk=b2[i];
				qc[i].bm=2;
			}
		}
		for(int i=1;i<=n;i++){
			lik=lik+zx[i].lk;
			if(zx[i].bm==1){
				bm1++;
			} else if(zx[i].bm==2){
				bm2++;
			} else{
				bm3++;
			}
			
		}
		
		if(bm1>pjz){
			lik=0;
			int js;
			for(int i=1;i<=n;i++){
				if(zx[i].bm==1){
					zzz1[j]=zx[i].lk;
				}
			}
			int max=-1;
			for(int i=1;i<=js;i++){
				for(int j=i+1;i<=js;j++){
					max=zzz1[i];
					if(i==js){
						break;
					}else(zzz1[i]<zzz1[i+1]){
						max==zzz1[i+1];
					}
				}
				zzz[i]=max;
				max==-1;
			}
			for(int i=1;i<=js;i++)lse{
			cout << lik;
		}
		cout << lik;
	}
	
	return 0;
}