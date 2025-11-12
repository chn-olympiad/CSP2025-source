#include<bits/stdc++.h>
using namespace std;
int x[500010];
int n,k;
int a[500010];
struct node{
    int l,da;
};
struct nextn{
    int now,n;
};
bool com(nextn n1,nextn n2){
    return n1.n<n2.n;
}
node dp[500010];
nextn nex[500010];
int main(){
    freopen("xor.in","r",stdin);//666 cha dian bu hui xie
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	x[0]=0;
	for(int i=1;i<=n;i++){
        cin>>a[i];
        x[i]=x[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
        int j=i;
        while(((x[i-1]^x[j])!=k)&&j<=n) j++;
        nex[i].n=j;nex[i].now=i;
	}
	sort(nex,nex+n,com);
	dp[0].da=0;dp[0].l=0;
	int last=0;
	for(int i=1;i<=n;){
        while(dp[last].l>=nex[i].now&&i<=n) i++;
        dp[i].da=dp[last].da+1;dp[i].l=nex[i].n;
        last=i;
        i+=1;
	}
	cout<<dp[last].da-1;
	return 0;
}
