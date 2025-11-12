#include<bits/stdc++.h>
using namespace std;
long long sum,k=998244353;
int n,tot,a[5005],b[5005][5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(n<=20){
    	for(int ia=1;ia<=n;ia++){
    	for(int ib=ia+1;ib<=n;ib++){
    	for(int ic=ib+1;ic<=n;ic++){
    		if(a[ia]+a[ib]>a[ic]) tot++;
    		tot%=k;
    	for(int id=ic+1;id<=n;id++){
    		if(a[ia]+a[ib]+a[ic]>a[id]) tot++;
    		tot%=k;
    	for(int ie=id+1;ie<=n;ie++){
    		if(a[ia]+a[ib]+a[ic]+a[id]>a[ie]) tot++;
    		tot%=k;
    	for(int ig=ie+1;ig<=n;ig++){
    		if(a[ia]+a[ib]+a[ic]+a[id]+a[ie]>a[ig]) tot++;
    		tot%=k;
    	for(int ih=ig+1;ih<=n;ih++){
    		if(a[ia]+a[ib]+a[ic]+a[id]+a[ie]+a[ig]>a[ih]) tot++;
    		tot%=k;
    	for(int ii=ih+1;ii<=n;ii++){
    		if(a[ia]+a[ib]+a[ic]+a[id]+a[ie]+a[ig]+a[ih]>a[ii]) tot++;
    		tot%=k;
    	for(int ij=ii+1;ij<=n;ij++){
    		if(a[ia]+a[ib]+a[ic]+a[id]+a[ie]+a[ig]+a[ih]+a[ii]>a[ij]) tot++;
    		tot%=k;
    	for(int ik=ij+1;ik<=n;ik++){
    		if(a[ia]+a[ib]+a[ic]+a[id]+a[ie]+a[ig]+a[ih]+a[ii]+a[ij]>a[ik]) tot++;
    		tot%=k;
    	for(int il=ik+1;il<=n;il++){
    		if(a[ia]+a[ib]+a[ic]+a[id]+a[ie]+a[ig]+a[ih]+a[ii]+a[ij]+a[ik]>a[il]) tot++;
    		tot%=k;
    	for(int im=il+1;im<=n;im++){
    		if(a[ia]+a[ib]+a[ic]+a[id]+a[ie]+a[ig]+a[ih]+a[ii]+a[ij]+a[ik]+a[il]>a[im]) tot++;
    	for(int in=im+1;in<=n;in++){
    		if(a[ia]+a[ib]+a[ic]+a[id]+a[ie]+a[ig]+a[ih]+a[ii]+a[ij]+a[ik]+a[il]+a[im]>a[in]) tot++;
    		tot%=k;
    	for(int io=in+1;io<=n;io++){
    		if(a[ia]+a[ib]+a[ic]+a[id]+a[ie]+a[ig]+a[ih]+a[ii]+a[ij]+a[ik]+a[il]+a[im]+a[in]>a[io]) tot++;
    		tot%=k;
    	for(int ip=io+1;ip<=n;ip++){
    		if(a[ia]+a[ib]+a[ic]+a[id]+a[ie]+a[ig]+a[ih]+a[ii]+a[ij]+a[ik]+a[il]+a[im]+a[in]+a[io]>a[ip]) tot++;
    		tot%=k;
    	for(int iq=ip+1;iq<=n;iq++){
    		if(a[ia]+a[ib]+a[ic]+a[id]+a[ie]+a[ig]+a[ih]+a[ii]+a[ij]+a[ik]+a[il]+a[im]+a[in]+a[io]+a[ip]>a[iq]) tot++;
    		tot%=k;
    	for(int ir=iq+1;ir<=n;ir++){
    		if(a[ia]+a[ib]+a[ic]+a[id]+a[ie]+a[ig]+a[ih]+a[ii]+a[ij]+a[ik]+a[il]+a[im]+a[in]+a[io]+a[ip]+a[iq]>a[ir]) tot++;
    		tot%=k;
    	for(int is=ir+1;is<=n;is++){
    		if(a[ia]+a[ib]+a[ic]+a[id]+a[ie]+a[ig]+a[ih]+a[ii]+a[ij]+a[ik]+a[il]+a[im]+a[in]+a[io]+a[ip]+a[iq]+a[ir]>a[is]) tot++;
    		tot%=k;
    	for(int it=is+1;it<=n;it++){
    		if(a[ia]+a[ib]+a[ic]+a[id]+a[ie]+a[ig]+a[ih]+a[ii]+a[ij]+a[ik]+a[il]+a[im]+a[in]+a[io]+a[ip]+a[iq]+a[ir]+a[is]>a[it]) tot++;
    		tot%=k;
    	for(int iu=it+1;iu<=n;iu++){
    		if(a[ia]+a[ib]+a[ic]+a[id]+a[ie]+a[ig]+a[ih]+a[ii]+a[ij]+a[ik]+a[il]+a[im]+a[in]+a[io]+a[ip]+a[iq]+a[ir]+a[is]+a[it]>a[iu]) tot++;
    		tot%=k;
    	for(int iv=iu+1;iv<=n;iv++){
    		if(a[ia]+a[ib]+a[ic]+a[id]+a[ie]+a[ig]+a[ih]+a[ii]+a[ij]+a[ik]+a[il]+a[im]+a[in]+a[io]+a[ip]+a[iq]+a[ir]+a[is]+a[it]+a[iu]>a[iv]) tot++;
    		tot%=k;
        }}}}}}}}}}}}}}}}}}}}}
        cout<<tot;
        return 0;
	}
    b[1][1]=1;
    for(int i=2;i<=n+1;i++){
    	for(int j=1;j<=i;j++){
    		long long x=b[i-1][j-1]+b[i-1][j];
    		x%=k;
    		b[i][j]=x;
		}
	}
	for(int i=4;i<=n+1;i++){
		sum+=b[n+1][i];
		sum%=k;
	}
	cout<<sum;
	return 0;
}
