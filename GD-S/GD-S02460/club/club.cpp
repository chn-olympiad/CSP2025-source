#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int a,b,c;
	int ma,ch1,zh,cmax,czh;
}xi[100005];
bool cmp(node x,node y){
	return x.ch1>y.ch1;
}
long long sum=0;
int k[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
//			xi[i].zh=0;xi[i].ch1=0;xi[i].cmax=0;xi[i].ma=0;xi[i].czh=0;
			scanf("%d%d%d",&xi[i].a,&xi[i].b,&xi[i].c);
			int ma=max(xi[i].a,max(xi[i].b,xi[i].c));
			xi[i].ma=ma;
			int cmax;
			if(ma==xi[i].a){
				xi[i].zh=1;
				cmax=max(xi[i].b,xi[i].c);
			}
			if(ma==xi[i].b){
				xi[i].zh=2;
				cmax=max(xi[i].a,xi[i].c);
			}
			if(ma==xi[i].c){
				xi[i].zh=3;
				cmax=max(xi[i].a,xi[i].b);
			}
			if(cmax==xi[i].a){
				xi[i].czh=1;
			}
			if(cmax==xi[i].b){
				xi[i].czh=2;
			}
			if(cmax==xi[i].c){
				xi[i].czh=3;
			}						
			xi[i].cmax=cmax;
			xi[i].ch1=ma-cmax;
		}
		for(int i=1;i<=3;i++){
			k[i]=0;
		}
		sort(xi+1,xi+1+n,cmp);
		for(int i=1;i<=n;i++){
//			cout<<xi[i].ma<<' '; 
			if(k[xi[i].zh]<n/2){
				sum+=xi[i].ma;
				k[xi[i].zh]++;
			}else{
				sum+=xi[i].cmax;
				k[xi[i].czh]++;
			}
//			cout<<sum<<' ';
		}
		cout<<sum<<endl;
	}
	return 0;
}
