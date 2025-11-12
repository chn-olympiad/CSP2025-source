#include <bits/stdc++.h>
using namespace std;
int con[5],a[100010],b[100010],c[100010];
struct hhm{
	int club;
	int myd;
}aa[100010];
struct hh{
	int bh;
	int maxz;
}bb[100010];
bool cmp1(hh p,hh q){
	return p.maxz>q.maxz;
}
bool cmp2(hhm x,hhm y){
	return x.myd>y.myd;
}
bool cmp3(hh p,hh q){
	return p.maxz>q.maxz;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	cin>>t;
	int px[100010][5];// i di 
	while(t--){
		long long ans=0;
		long long ans1=0;
		cin>>n;
		for(int i=1;i<=n;i++) bb[i].bh=i;
		
		for(int i=1;i<=n;i++){
			for(int i=1;i<=3;i++) aa[i].club=i;
			cin>>a[i]>>b[i]>>c[i];
			aa[1].myd=a[i];
			aa[2].myd=b[i];
			aa[3].myd=c[i];
			sort(aa+1,aa+4,cmp2);
			
			
			px[i][1]=aa[1].club;
			px[i][2]=aa[2].club;
			px[i][3]=aa[3].club;
			bb[i].maxz=max(max(a[i],b[i]),c[i]);
			
			//cout<<px[i][1]<<px[i][2]<<px[i][3]<<endl;
		}
		con[1]=0;
		con[2]=0;
		con[3]=0;
		sort(bb+1,bb+n+1,cmp1);
		for(int i=1;i<=n;i++){
			int wow=1;
			int j=bb[i].bh;
			if(con[px[j][wow]]>=(n/2)){
				wow++;
			}
			if(con[px[j][wow]]>=(n/2)){
				wow++;
			}
			if(px[j][wow]==1){
				ans+=a[j];
				con[1]++;
			}
			else if(px[j][wow]==2){
				ans+=b[j];
				con[2]++;
			}
			else if(px[j][wow]==3){
				ans+=c[j];
				con[3]++;
			}
		}
		con[1]=0;
		con[2]=0;
		con[3]=0;
		for(int i=n;i>=1;i--){
			int wow=1;
			int j=bb[i].bh;
			if(con[px[j][wow]]>=(n/2)){
				wow++;
			}
			if(con[px[j][wow]]>=(n/2)){
				wow++;
			}
			if(px[j][wow]==1){
				ans1+=a[j];
				con[1]++;
			}
			else if(px[j][wow]==2){
				ans1+=b[j];
				con[2]++;
			}
			else if(px[j][wow]==3){
				ans1+=c[j];
				con[3]++;
			}
		}
		
		
		
		cout<<max(ans,ans1)<<endl;
	}
	return 0;
}
