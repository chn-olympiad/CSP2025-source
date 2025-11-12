#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,T;
int aa[N],bb[N],cc[N],a[N];
int a1,b,c;
int ans=0;
int cnt;
bool flag=true;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		cnt=n/2;
		for(int i=1;i<=n;i++){
			cin>>aa[i]>>bb[i]>>cc[i];
			if(bb[i]!=cc[i]||bb[i]!=0||cc[i]!=0) flag=false;
		}
		if(flag==true){
			sort(aa+1,aa+1+n);
			for(int i=n;i>cnt;i--){
				ans+=aa[i];
			}
		}
		if(n==2){
				a[1]=aa[1]+bb[2];
				a[2]=aa[1]+cc[2];
				a[3]=bb[1]+aa[2];
				a[4]=bb[1]+cc[2];
				a[5]=cc[1]+aa[2];
				a[6]=cc[1]+bb[2];
				sort(a+1,a+1+6);
				ans=a[6];
		}
		else if(n==4){
			a[1]=aa[1]+aa[2]+bb[3]+bb[4];
			a[2]=aa[1]+aa[2]+bb[3]+cc[4];
			a[3]=aa[1]+aa[2]+cc[3]+cc[4];
			a[4]=aa[1]+aa[3]+bb[4]+cc[2];
			a[5]=aa[1]+aa[3]+bb[4]+bb[2];
			a[6]=aa[1]+aa[3]+cc[4]+cc[2];
			a[7]=aa[1]+aa[4]+bb[2]+cc[3];
			a[8]=aa[1]+aa[4]+bb[2]+bb[3];
			a[9]=aa[1]+aa[4]+cc[2]+cc[3];
			a[10]=aa[2]+aa[3]+bb[1]+bb[4];
			a[11]=aa[2]+aa[3]+bb[1]+cc[4];
			a[12]=aa[2]+aa[3]+cc[1]+cc[4];
			a[13]=aa[2]+aa[4]+bb[1]+cc[3];
			a[14]=aa[2]+aa[4]+bb[1]+bb[3];
			a[15]=aa[2]+aa[4]+cc[1]+cc[3];
			a[16]=aa[3]+aa[4]+bb[1]+bb[2];
			a[17]=aa[3]+aa[4]+bb[1]+cc[2];
			a[18]=aa[3]+aa[4]+cc[1]+cc[2];
			a[19]=bb[1]+bb[2]+aa[3]+cc[4];
			a[20]=bb[1]+bb[2]+cc[3]+cc[4];
			a[21]=bb[1]+bb[3]+aa[2]+cc[4];
			a[22]=bb[1]+bb[3]+cc[2]+cc[4];
			a[23]=bb[1]+bb[4]+aa[2]+cc[3];
			a[24]=bb[1]+bb[4]+cc[2]+cc[3];
			a[25]=bb[1]+bb[2]+cc[3]+aa[4];
			a[26]=bb[1]+bb[3]+cc[2]+aa[4];
			a[27]=bb[1]+bb[4]+cc[2]+aa[3];
			a[28]=bb[2]+bb[3]+aa[1]+cc[4];
			a[29]=bb[2]+bb[3]+cc[1]+aa[4];
			a[30]=bb[2]+bb[3]+cc[1]+cc[4];
			a[31]=bb[2]+bb[4]+aa[1]+cc[3];
			a[32]=bb[2]+bb[4]+cc[1]+aa[3];
			a[33]=bb[2]+bb[3]+cc[1]+cc[3];
			a[34]=bb[3]+bb[4]+aa[1]+cc[2];
			a[35]=bb[3]+bb[4]+cc[1]+aa[2];
			a[36]=bb[3]+bb[4]+cc[1]+cc[2];
			a[37]=aa[1]+aa[2]+cc[3]+bb[4];
			a[38]=aa[1]+aa[3]+cc[4]+bb[2];
			a[39]=aa[1]+aa[4]+cc[2]+bb[3];
			a[40]=aa[2]+aa[3]+cc[1]+bb[4];
			a[41]=aa[2]+aa[4]+cc[1]+cc[3];
			a[42]=aa[3]+aa[4]+cc[1]+bb[2];
			a[43]=cc[1]+cc[2]+bb[3]+aa[4];
			a[44]=cc[1]+cc[2]+aa[3]+bb[4];
			a[45]=cc[1]+cc[3]+aa[2]+bb[4];
			a[46]=cc[1]+cc[3]+bb[2]+aa[4];
			a[47]=cc[1]+cc[4]+aa[2]+bb[3];
			a[48]=cc[1]+cc[4]+bb[2]+aa[3];
			a[49]=cc[2]+cc[3]+aa[1]+bb[4];
			a[50]=cc[2]+cc[3]+bb[1]+aa[4];
			a[51]=cc[2]+cc[4]+bb[1]+aa[3];
			a[52]=cc[2]+cc[4]+aa[1]+bb[3];
			a[53]=cc[3]+cc[4]+aa[1]+bb[2];
			a[54]=cc[3]+cc[4]+bb[1]+aa[2];
			sort(a+1,a+1+54);
			ans=a[54];
		}
		else{
			for(int i=1;i<=n;i++){
				int mx=max(aa[i],bb[i]);
				mx=max(mx,cc[i]);
				if(mx==aa[i]) a1++;
				else if(mx==bb[i]) b++;
				else if(mx==cc[i]) c++;
				int mn=min(aa[i],bb[i]);
				mn=min(mn,cc[i]);
				if(aa[i]!=mn&&aa[i]!=mx) int c=aa[i];
				else if(bb[i]!=mn&&bb[i]!=mx) int c=bb[i];
				else if(cc[i]!=mn&&cc[i]!=mx) int c=cc[i];
				if(a1<cnt&&b<cnt&&c<cnt) ans+=mx;
				else ans+=c;
			}
		}
		cout<<ans<<endl;
		a1=0,b=0,c=0;
	}
    return 0;
}
