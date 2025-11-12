#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
int t,n;
long long sum[MAXN],num[4];
bool flag[4];

struct Node{
	int a1,a2,a3;
} a[MAXN];

void ANS(){
	memset(sum,0,sizeof(sum));
	memset(flag,0,sizeof(flag));
	memset(num,0,sizeof(num));
	for(int i=1;i<=n;++i){
		if(!flag[1]) sum[i]=max(sum[i],sum[i-1]+a[i].a1); 
		if(!flag[2]) sum[i]=max(sum[i],sum[i-1]+a[i].a2);
		if(!flag[3]) sum[i]=max(sum[i],sum[i-1]+a[i].a3);
		if(sum[i]==sum[i-1]+a[i].a1){
			++num[1];
			if(num[1]==(n/2)) flag[1]=true;
		} 
		else if(sum[i]==sum[i-1]+a[i].a2){
			++num[2];
			if(num[2]==(n/2)) flag[2]=true;
		} 
		else if(sum[i]==sum[i-1]+a[i].a3){
			++num[3];
			if(num[3]==(n/2)) flag[3]=true;
		}
	}
	cout<<sum[n]<<'\n';
}

int main(){
   freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
   cin>>t;
   for(int i=1;i<=t;++i){
   	    cin>>n;
   	    for(int j=1;j<=n;++j){
   	    	cin>>a[j].a1>>a[j].a2>>a[j].a3;
	    }
	    ANS();
   }
   return 0;
}