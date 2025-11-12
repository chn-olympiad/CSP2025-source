#include<bits/stdc++.h>
using namespace std;
int s[100005],a[100005],b[100005],c[100005],n,t,flgA,flgB,ans;

void start(){
	for(int i=1;i<=n;i++){
		a[i]=0; b[i]=0; c[i]=0; ans=0; flgA=0; flgB=0;
	}
}
bool cmp(int a,int b){
	return a>b;
}
void planA(){
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n/2;i++) ans+=a[i];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i0=1;i0<=t;i0++){
		if(i0>1) start();
		cin>>n;
		for(int i=1;i<=n;i++) scanf("%d %d %d",&a[i],&b[i],&c[i]);
		for(int i=1;i<=n;i++){
			if(b[i]==0&&c[i]==0) flgA++;
//			if(c[i]==0) flgB++;
		} 
		if (flgA==n) planA();
//		if (flgB==n) planB();
		cout<<ans<<endl;
	}
	return 0;
} 
