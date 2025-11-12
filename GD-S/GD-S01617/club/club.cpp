#include<bits/stdc++.h>
using namespace std;
int n,t,jd;
long long sum;
struct fool{
	int cnt1;
	int cnt2;
	int cnt3;
}s[100010];
void dg(long long summ,int step,int c1,int c2,int c3,int e){
	if(e==1&&c1>jd||e==2&&c2>jd||e==3&&c3>jd){
		return ;
		}
	if(step==n+1){
		sum=max(sum,summ);
		return ;
	}

	dg(summ+s[step].cnt1,step+1,c1+1,c2,c3,1);
	dg(summ+s[step].cnt2,step+1,c1,c2+1,c3,2);
    dg(summ+s[step].cnt3,step+1,c1,c2,c3+1,3);
    return ;

}
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
    	jd=n/2;
		for(int i=1;i<=n;i++){
		cin>>s[i].cnt1;
		cin>>s[i].cnt2;
		cin>>s[i].cnt3;
	   }
        sum=0;
		dg(0,1,0,0,0,0);
        cout<<sum<<endl;
	}
	return 0;
} 
