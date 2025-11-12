#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int t,n,d;
long long a1[N],a2[N],a3[N];

bool cmp(int a,int b){
	return a%100000>b%100000;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n;
		d=2;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i] && d)d=1;
			if(a3[i])d=0;
		}
		
		if(n==2){
			int sum=0,p,maxn=0;
			for(int i=1;i<=n;i++){
				if(a1[i]>maxn)maxn=a1[i],p=i;
				if(a2[i]>maxn)maxn=a2[i],p=i;
				if(a3[i]>maxn)maxn=a3[i],p=i;
			}
			sum+=maxn;
			maxn=0;
			if(p==1){
				if(a1[2]>maxn)maxn=a1[2];
				if(a2[2]>maxn)maxn=a2[2];
				if(a3[2]>maxn)maxn=a3[2];
			}
			if(p==2){
				if(a1[1]>maxn)maxn=a1[1];
				if(a2[1]>maxn)maxn=a2[1];
				if(a3[1]>maxn)maxn=a3[1];
			}
			sum+=maxn;
			cout<<sum<<"\n";
		}
		else if(d==2){
			int sum=0;
			sort(a1+1,a1+n+1);
			for(int i=n/2+1;i<=n;i++){
				sum+=a1[i];
			}
			cout<<sum<<"\n";
		}
		else if(d==1){
			int c1=0,c2=0,sum=0;
			for(int i=1;i<=n;i++){
				a3[i]=abs(a1[i]-a2[i])+100000*i;
			}
			sort(a3+1,a3+n+1,cmp);
			for(int i=1;i<=n;i++){
				int p=a3[i]/100000;
				if((a1[p]>a2[p] && c1<=n/2) || c2>n/2){sum+=a1[p],c1++;}
				else sum+=a2[p],c2++;
			}
			cout<<sum<<"\n";
		}
		else{
			cout<<0<<"\n";
		}
	}
	return 0;
}
