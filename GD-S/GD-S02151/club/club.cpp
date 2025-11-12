#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n,w[N][4],ans,len1,len2,len3,a[N],b[N],c[N];
bool cmp(int x,int y){
	return x>y;
}
void work(){
	ans=len1=len2=len3=n=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i][1]>>w[i][2]>>w[i][3];
		if(w[i][1]>=w[i][2]&&w[i][1]>=w[i][3]){
			a[++len1]=w[i][1];
			ans+=w[i][1];
		}
		else if(w[i][2]>=w[i][1]&&w[i][2]>=w[i][3]){
			b[++len2]=w[i][2];
			ans+=w[i][2]; 
		}
		else if(w[i][3]>=w[i][2]&&w[i][3]>=w[i][1]){
			c[++len3]=w[i][3];
			ans+=w[i][3];
		}
	}
	if(len1>n/2){
		sort(a+1,a+1+len1,cmp);
		for(int i=len1;i>n/2;i--)ans-=a[i];
	}
	else if(len2>n/2){
		sort(b+1,b+1+len2,cmp);
		for(int i=len1;i>n/2;i--)ans-=b[i];
	} 
	else if(len3>n/2){
		sort(c+1,c+1+len3,cmp);
		for(int i=len1;i>n/2;i--)ans-=c[i];
	}
	cout<<ans<<endl;//I hope it will be right.
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tcase;//why do this problem has duoce?
	cin>>tcase;
	while(tcase--)work();
}
