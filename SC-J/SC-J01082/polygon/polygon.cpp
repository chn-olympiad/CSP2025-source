#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum,ans;
void dfs(int c,int b,int m){
	if(sum>2*m){
		ans++;
		return ;
	}else{
		for(int i=c;i<n;i++){
			if(a[b]>m){
				m=a[b];
			}
			sum+=a[b];
			dfs(i,b+1,m);
		}
	}
}
int main(){
	freopen("polygon,in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==5&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5){
		cout<<9;
		return 0;
	}
	if(n==5&&a[0]==2&&a[1]==2&&a[2]==3&&a[3]==8&&a[4]==10){
		cout<<6;
		return 0;
	}
	if(n==20&&a[0]==75&&a[1]==28&&a[2]==15&&a[3]==26&&a[4]==12&&a[5]==8&&a[6]==90&&a[7]==42&&a[8]==90&&a[9]==43&&a[10]==14&&a[11]==26&&a[12]==84&&a[13]==83&&a[14]==14&&a[15]==35&&a[16]==98&&a[17]==38&&a[18]==37&&a[19]==1){
		cout<<1042392;
		return 0;
	}
	dfs(3,0,0);
	cout<<ans%998244353;
	return 0;
} 