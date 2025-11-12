#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}q[100010];
int au[100010],bu[100010],cu[100010],tota=0,totb=0,totc=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		long long ret=0;
		for(int j=1;j<=n;j++){
			cin>>q[j].a>>q[j].b>>q[j].c;
			if(max(q[j].a,max(q[j].b,q[j].c))==q[j].a){
				ret+=q[j].a;
				au[++tota]=j;
			}else if(max(q[j].a,max(q[j].b,q[j].c))==q[j].b){
				bu[++totb]=j;
				ret+=q[j].b;
			}else{
				cu[++totc]=j;
				ret+=q[j].c;
			}
		}
		if(tota>n/2){
			for(int j=1;j<=tota;j++){
				au[j]=q[au[j]].a-max(q[au[j]].b,q[au[j]].c);
			}
			sort(au+1,au+tota+1);
			for(int j=1;j<=tota-n/2;j++){
				ret-=au[j];
			}
		}else if(totb>n/2){
			for(int j=1;j<=totb;j++){
				bu[j]=q[bu[j]].b-max(q[bu[j]].a,q[bu[j]].c);
			}
			sort(bu+1,bu+totb+1);
			for(int j=1;j<=totb-n/2;j++){
				ret-=bu[j];
			}
		}else{
			for(int j=1;j<=totc;j++){
				cu[j]=q[cu[j]].c-max(q[cu[j]].b,q[cu[j]].a);
			}
			sort(cu+1,cu+totc+1);
			for(int j=1;j<=totc-n/2;j++){
				ret-=cu[j];
			}
		}
		tota=0;
		totb=0;
		totc=0;
		cout<<ret<<endl;
	}
	return 0;
}
