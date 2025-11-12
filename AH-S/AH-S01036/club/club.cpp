#include<bits/stdc++.h>
using namespace std;
int t;
struct sb{
	int st,nd,rd;
};
bool cmp(sb a,sb b){
	int mxa=-1,mxb=-1,na=0,nb=0;
	if(a.st>mxa) na=1,mxa=a.st;
	if(a.nd>mxa) na=2,mxa=a.nd;
	if(a.rd>mxa) na=3,mxa=a.rd;
	if(b.st>mxb) nb=1,mxb=b.st;
	if(b.nd>mxb) nb=2,mxb=b.nd;
	if(b.rd>mxb) nb=3,mxb=b.rd;
	if(na==1){
		if(nb==1) return a.st>b.st;
		if(nb==2) return a.st>b.nd;
		if(nb==3) return b.st>b.rd;
	}else if(na==2){
		if(nb==1) return a.nd>b.st;
		if(nb==2) return a.nd>b.nd;
		if(nb==3) return b.nd>b.rd;
	}else{
		if(nb==1) return a.rd>b.st;
		if(nb==2) return a.rd>b.nd;
		if(nb==3) return a.rd>b.rd;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,one=0,two=0,three=0,ans=0;
		sb a[100001];
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].st,&a[i].nd,&a[i].rd);
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].st>a[i].nd && a[i].st>a[i].rd){
				if(one<n/2) one++,ans+=a[i].st;
				else if(a[i].nd>a[i].rd) two++,ans+=a[i].nd;
				else three++,ans+=a[i].rd;
			}else if(a[i].nd>a[i].rd){
				if(two<n/2) two++,ans+=a[i].nd;
				else if(a[i].st>a[i].rd) one++,ans+=a[i].st;
				else three++,ans+=a[i].rd;
			}else{
				if(three<n/2) three++,ans+=a[i].rd;
				else if(a[i].st>a[i].nd) one++,ans+=a[i].st;
				else two++,ans+=a[i].nd;
			}
		}
		cout<<ans<<endl;
	}
}
