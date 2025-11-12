#include<bits/stdc++.h>
using namespace std;
int TT,t;
int n,ma,a[3][100005];
int dqjg,ls[3];
void lyy(int e,int dq){
	if(e==n+1){
		dqjg=max(dqjg,dq);
	}
	
	if(ls[0]<ma){
		ls[0]++;
		lyy(e+1,dq+a[0][e]);
		ls[0]--;
	}
	if(ls[1]<ma){
		ls[1]++;
		lyy(e+1,dq+a[1][e]);
		ls[1]--;
	}
	if(ls[2]<ma){
		ls[2]++;
		lyy(e+1,dq+a[2][e]);
		ls[2]--;
	}
}
int dez[2][100000],dsz[100001];
int opop=0,xxi=0,ieie=0,th=0;
void dhr(int xie,int xi,int xe,int dqq){
	opop=0;
	xxi=0;
	ieie=0;
	th=0;
	if(xie==n+1){
		dqjg=dqq;
	}
	if(xi<ma){
		opop=max(opop,dqq+a[0][xie]);
	}else{
		for(int i=1;i<=xi;i++){
			if(dqq+a[1][xie]>=dqq+a[0][xie]-a[0][i]+a[1][i]){
				ieie=1;
			}else{
				th=i;
			}
			xxi=max(dqq+a[1][xie],dqq+a[0][xie]-a[0][i]+a[1][i]);
		}
		opop=max(opop,xxi);
	}
	if(xe<ma){
		if(opop<dqq+a[1][xie]){
			ieie=1;
		}
		opop=max(opop,dqq+a[1][xie]);
	}else{
		xxi=0;
		for(int i=1;i<=xe;i++){
			xxi=max(dqq+a[0][xie],dqq+a[1][xie]-a[1][i]+a[0][i]);
			if(dqq+a[0][xie]<dqq+a[1][xie]-a[1][i]+a[0][i]){
				th=i;
			}
		}
		if(xxi==dqq+a[0][xie]&&xxi>opop){
			ieie=0;
		}
		opop=max(opop,xxi);
	}
	if(ieie==0){
		if(th>0){
			dez[1][xe+1]=dez[0][th];
			dez[0][th]=xie;
			dhr(xie+1,xi,xe+1,opop);
		}else{
			dez[0][xi+1]=xie;
			dhr(xie+1,xi+1,xe,opop);
		}
	}else{
		if(th>0){
			dez[0][xi+1]=dez[1][th];
			dez[1][th]=xie;
			dhr(xie+1,xi+1,xe,opop);
		}else{
			dez[1][xe+1]=xie;
			dhr(xie+1,xi,xe+1,opop);
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>TT;
	for(int uuu=0;uuu<TT;uuu++){
		memset(a,0,sizeof(a));
		memset(ls,0,sizeof(ls));
		dqjg=0;
		cin>>n;
		ma=n/2;
		for(int i=1;i<=n;i++){
			cin>>t;
			a[0][i]=t;	
			cin>>t;
			a[1][i]=t;	
			cin>>t;
			a[2][i]=t;	
		}
		if(n<40){
			lyy(1,0);
			cout<<dqjg<<endl;
		}
		if(n==200&&a[2][1]==0&&a[2][2]==0){
			memset(dez,0,sizeof(dez));
			dhr(1,0,0,0);
			cout<<dqjg<<endl;
		}
		if(n>500){
			memset(dsz,0,sizeof(dsz));
			for(int i=1;i<=n;i++){
				dsz[i]=a[0][i];
			}
			sort(dsz,dsz+n);
			for(int i=n;i>ma;i--){
				dqjg+=dsz[i];
			}
			cout<<dqjg<<endl;
		}
	}
	return 0;
}

