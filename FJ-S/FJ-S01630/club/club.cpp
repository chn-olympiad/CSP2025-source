
#include<bits/stdc++.h>
using namespace std;\
int t,n,a[10][100005],ab[100005],ac[100005],bc[100005];
bool cab(int x,int y){
	return a[2][x]-a[3][x]<a[2][y]-a[3][y];
}
bool cac(int x,int y){
	return a[2][x]-a[4][x]<a[2][y]-a[4][y];
}
bool cbc(int x,int y){
	return a[3][x]-a[4][x]<a[3][y]-a[4][y];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(ab,0,sizeof(ab));
		memset(ac,0,sizeof(ac));
		memset(bc,0,sizeof(bc));
		int as=0,bs=0,cs=0,ak=0,bk=0,ck=0;
		for(int i=1;i<=n;i++){
			a[1][i]=i;
			cin>>a[2][i]>>a[3][i]>>a[4][i];
			int mmm=max(a[2][i],max(a[3][i],a[4][i]));
			if(mmm=a[2][i]){
				a[5][i]=1;
				as++;
				ak+=a[2][i];
			}
			if(mmm=a[3][i]){
				a[5][i]=2;
				bs++;
				bk+=a[3][i];
			}
			if(mmm=a[4][i]){
				a[5][i]=3;
				cs++;
				ck+=a[4][i];
			}
			ab[i]=i;
			ac[i]=i;
			bc[i]=i;
		}
		sort(ab+1,ab+n+1,cab);
		sort(ac+1,ac+n+1,cac);
		sort(bc+1,bc+n+1,cbc);
		int ans=0;
		if(as>n/2){
			int xs=as-n/2;
			for(int k=0;k<=xs;k++){
				int akk=ak,bkk=bk,ckk=ck;
				for(int m=1;m<=k;m++){
					akk-=a[2][ab[m]];
					bkk+=a[3][ab[m]];
				}
				for(int m=k+1;m<=xs;m++){
					akk-=a[2][ac[m]];
					ckk+=a[4][ac[m]];
				}
				ans=max(ans,akk+bkk+ckk);
			}
		}
		if(bs>n/2){
			int xs=bs-n/2;
			for(int k=0;k<=xs;k++){
				int akk=ak,bkk=bk,ckk=ck;
				for(int m=1;m<=k;m++){
					bkk-=a[3][ab[m]];
					akk+=a[2][ab[m]];
				}
				for(int m=k+1;m<=xs;m++){
					bkk-=a[3][bc[m]];
					ckk+=a[4][bc[m]];
				}
				ans=max(ans,akk+bkk+ckk);
			}
		}
		if(cs>n/2){
			int xs=cs-n/2;
			for(int k=0;k<=xs;k++){
				int akk=ak,bkk=bk,ckk=ck;
				for(int m=1;m<=k;m++){
					ckk-=a[4][bc[m]];
					bkk+=a[3][bc[m]];
				}
				for(int m=k+1;m<=xs;m++){
					ckk-=a[4][ac[m]];
					akk+=a[2][ac[m]];
				}
				ans=max(ans,akk+bkk+ckk);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}












