#include<bits/stdc++.h>
using namespace std;
int t,n;
struct TAT{
	int m;
	int k;
}a[100005],b[100005],c[100005];
int Flag[100005][2],num[100005][4];
int sum[100005];
int cmp(TAT x,TAT y){
	return x.m>y.m;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		memset(Flag,0,sizeof(Flag));
		long long Max=0;
		int A=2,B=2,C=2;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j].m>>b[j].m>>c[j].m;
			num[j][1]=a[j].m;
			num[j][2]=b[j].m;
			num[j][3]=c[j].m;
			a[j].k=j; b[j].k=j; c[j].k=j;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		for(int j=1;j<=n/2;j++){
			Flag[a[j].k][0]=a[j].m;
			Flag[a[j].k][1]=1;
		}
		for(int j=1;j<=n/2;j++){
			if(Flag[b[j].k][1]!=0){
				if(b[j].m+a[A].m>Flag[b[j].k][0]+b[B].m){
					Flag[b[j].k][0]=b[j].m;
					Flag[a[A].k][0]=a[A].m;
					Flag[b[j].k][1]=2;
					Flag[a[A].k][1]=2;
					A++;
				}else{
					Flag[b[B].k][0]=b[B].m;
					Flag[b[B].k][1]=2;
					B++;
				}
			}else{
				Flag[b[j].k][0]=b[j].m;
				Flag[b[j].k][1]=2;
			}
		}
		for(int j=1;j<=n/2;j++){
			if(Flag[c[j].k][1]==1){
				if(c[j].m+a[A].m>Flag[c[j].k][0]+c[C].m){
					Flag[c[j].k][0]=c[j].m;
					Flag[a[A].k][0]=a[A].m;
					Flag[c[j].k][1]=3;
					Flag[a[A].k][1]=3;
					A++;
				}else{
					Flag[c[C].k][0]=c[C].m;
					Flag[c[C].k][1]=3;
					C++;
				}
			}else if(Flag[c[j].k][1]==2){
				if(c[j].m+b[B].m>Flag[c[j].k][0]+c[C].m){
					Flag[c[j].k][0]=c[j].m;
					Flag[b[B].k][0]=b[B].m;
					Flag[c[j].k][1]=3;
					Flag[b[B].k][1]=3;
					B++;
				}else{
					Flag[c[C].k][0]=c[C].m;
					Flag[c[C].k][1]=3;
					C++;
				}
			}else{
				Flag[c[j].k][0]=c[j].m;
				Flag[c[j].k][1]=3;
			}
		}
		A=0; B=0; C=0;
		for(int j=1;j<=n;j++){
			a[j].m=0; b[j].m=0; c[j].m=0; 
			if(Flag[j][1]==1)A++;
			else if(Flag[j][1]==2)B++;
			else C++;
		}
		for(int j=1;j<=n;j++){
			if(num[j][1]>Flag[j][0]&&A<n/2){
				a[j].m=num[j][1]-Flag[j][0];
			}
			if(num[j][2]>Flag[j][0]&&B<n/2){
				b[j].m=num[j][2]-Flag[j][0];
			}
			if(num[j][3]>Flag[j][0]&&C<n/2){
				c[j].m=num[j][3]-Flag[j][0];
			}
			Flag[j][0]+=max(a[j].m,max(b[j].m,c[j].m));
		}
		for(int j=1;j<=n;j++) Max+=Flag[j][0];
		/*
		for(int j=1;j<=n;j++){
			cout<<a[j].m<<" "<<a[j].k<<endl;
		}
		cout<<endl;
		for(int j=1;j<=n;j++){
			cout<<b[j].m<<" "<<b[j].k<<endl;
		}
		cout<<endl;
		for(int j=1;j<=n;j++){
			cout<<c[j].m<<" "<<c[j].k<<endl;
		}
		cout<<endl;
		for(int j=1;j<=n;j++){
			cout<<Flag[j][0]<<" "<<Flag[j][1]<<endl;
		}
		cout<<A<<" "<<B<<" "<<C<<endl;
		*/
		cout<<Max<<endl;
		//cout<<endl;
	}
	return 0;
}

