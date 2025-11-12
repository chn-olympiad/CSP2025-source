#include<bits/stdc++.h>
using namespace std;
struct ans2{
	int s,e;
}s[500005];
bool cmp(ans2 x,ans2 y){
	if(x.e!=y.e)return x.e<y.e;
	else return x.s<y.s;
}
int n,k,a[500005],ans,num[500005],jg,m,bg;
int x,y;
bool A=1,B=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)A=0;
		if(a[i]>1)B=0;
	}
	if(A){
		if(k==1)cout<<n<<endl;
		else if(k==0)cout<<n/2<<endl;
		else cout<<0<<endl;
		return 0;
	}
	if(B){
		if(k==1){
			for(int i=1;i<=n;i++)if(a[i]==1)ans++;
			cout<<ans<<endl;
			return 0;
		}else if(k==0){
			for(int i=1;i<=n;i++){
				if(i!=1&&a[i-1]==1)a[i]=0;
				if(a[i]==0)ans++;
			}
			cout<<ans<<endl;
			return 0;
		}else{
			cout<<0<<endl;
			return 0;
		}
	}
	num[1]=a[1];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=20;j++){
			x=(num[i-1]>>(j-1))&1;
			y=(a[i]>>(j-1))&1;
			if((x==1&&y==0)||(x==0&&y==1))num[i]+=1<<(j-1);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			jg=0;
			if(i==1)jg=num[j];
			else 
			for(int z=1;z<=20;z++){
				x=(num[i-1]>>(z-1))&1;
				y=(num[j]>>(z-1))&1;
				if((x==1&&y==0)||(x==0&&y==1))jg+=1<<(z-1);
			}
		//	cout<<i<<" "<<j<<" "<<jg<<endl;
			if(jg==k){
				m++;
				s[m].s=i;
				s[m].e=j;
				break;
			}
		}
	}
	sort(s+1,s+1+m,cmp);
	bg=0;
	for(int i=1;i<=m;i++){
		if(s[i].s>bg){
			ans++;
			bg=s[i].e;
		}
	}
	cout<<ans<<endl;
	return 0;
}
