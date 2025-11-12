//GZ-S00102   周天翼   遵义市航天实验中学 
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int t,n;
struct people{
	int fi,se,th;
	int fiid,seid,thid;
	int cha1,cha2;
}a[100001];
bool cmp(people x,people y){
	if(x.cha1!=y.cha1){
		return x.cha1>y.cha1;
	}
	return x.cha2>y.cha2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    for(int k=1;k<=t;k++){
    	long long ans=0;
    	cin>>n;
    	int x1,x2,x3;
    	for(int i=1;i<=n;i++){
    		cin>>x1>>x2>>x3;
    		if(x1>=x2&&x1>=x3){
    			a[i].fi=x1;
    			a[i].fiid=1;
    			if(x2>x3){
    				a[i].se=x2;
    				a[i].seid=2;
    				a[i].th=x3;
    				a[i].thid=3;
				}
				else{
					a[i].se=x3;
    				a[i].seid=3;
    				a[i].th=x2;
    				a[i].thid=2;
				}
			}
			else if(x2>=x1&&x2>=x3){
    			a[i].fi=x2;
    			a[i].fiid=2;
    			if(x1>x3){
    				a[i].se=x1;
    				a[i].seid=1;
    				a[i].th=x3;
    				a[i].thid=3;
				}
				else{
					a[i].se=x3;
    				a[i].seid=3;
    				a[i].th=x1;
    				a[i].thid=1;
				}
			}
			else{
			    a[i].fi=x3;
    			a[i].fiid=3;
    			if(x1>x2){
    				a[i].se=x1;
    				a[i].seid=1;
    				a[i].th=x2;
    				a[i].thid=2;
				}
				else{
					a[i].se=x2;
    				a[i].seid=2;
    				a[i].th=x1;
    				a[i].thid=1;
				}
			}
			a[i].cha1=a[i].fi-a[i].se;
			a[i].cha2=a[i].se-a[i].th;
		}
		sort(a+1,a+1+n,cmp);
		int sum[4]={};
		for(int i=1;i<=n;i++){
			if(sum[a[i].fiid]+1<=n/2){
				ans+=a[i].fi;
				sum[a[i].fiid]++;
			}
			else if(sum[a[i].seid]+1<=n/2){
				ans+=a[i].se;
				sum[a[i].seid]++;
			}
			else{
				ans+=a[i].th;
				sum[a[i].thid]++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
