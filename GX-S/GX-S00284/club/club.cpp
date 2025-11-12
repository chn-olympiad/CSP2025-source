#include<bits/stdc++.h>
using namespace std;
struct node{
	int z1,z2;
};
bool cmp1(node i,node j){
	int x=min(i.z1,i.z2);
	int y=min(j.z1,j.z2);
	return x<y;
}
bool cmp2(node i,node j){
	return i.z1<j.z1;
}
bool cmp3(node i,node j){
	return i.z2<j.z2;
}
int main(){
	int i,tt;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>tt;
	for(int ii=1;ii<=tt;ii++){
		node ma[100003]={0};
		int na=0;
		node mb[100003]={0};
		int nb=0;
		node mc[100003]={0};
		int nc=0;
		int sum=0;
		int n;
		cin>>n;
		for(i=1;i<=n;i++){
			int x,y,z;
			int xx;
			cin>>x>>y>>z;
			xx=max(x,max(y,z));
			sum=sum+xx;
			if(xx==x){
				na++;
				ma[na].z1=x-y;
				ma[na].z2=x-z;
			}
			else if(xx==y){
				nb++;
				mb[nb].z1=y-x;
				mb[nb].z2=y-z;
			}
			else{
				nc++;
				mc[nc].z1=z-y;
				mc[nc].z2=z-x;
			}
		}
		int m=n/2;
		if(na<=m && nb<=m && nc<=m){
			cout<<sum<<endl;
			continue;
		}
		else if(na>=nb && na>=nc){
			sort(ma+1,ma+1+na,cmp1);
			for(i=1;na-m>0;i++){
				na--;
				if(ma[i].z2>ma[i].z1 || (ma[i].z1==ma[i].z2 && nb<=nc)){
					nb++;
					sum=sum-ma[i].z1;
					swap(mb[nb],ma[i]);
					mb[nb].z2=mb[nb].z2-mb[nb].z1;
				}
				else{
					nc++;
					sum=sum-ma[i].z2;
					swap(mc[nc],ma[i]);
					mc[nc].z1=mc[nc].z1-mc[nc].z2;
				}
			}
			if(na<=m && nb<=m && nc<=m){
				cout<<sum<<endl;
				continue;
			}
			else if(nb>m){
				sort(mb+1,mb+1+nb,cmp3);
				for(i=1;nb-m>0;i++){
					nb--;
					nc++;
					sum=sum-mb[i].z2;
				}
			}
			else{
				sort(mc+1,mc+1+nc,cmp1);
				for(i=1;nc-m>0;i++){
						nc--;
						nb++;
						sum=sum-mc[i].z1;
				}
			}
			cout<<sum<<endl;
			continue;
		}
		else if(nb>=na && nb>=nc){
			sort(mb+1,mb+1+nb,cmp1);
			for(i=1;nb-m>0;i++){
				nb--;
				if(mb[i].z2>mb[i].z1 || (mb[i].z2==mb[i].z1 && na<=nc)){
					na++;
					sum=sum-mb[i].z1;
					swap(ma[na],mb[i]);
					ma[na].z2=ma[nb].z2-ma[nb].z1;
				}
				else{
					nc++;
					sum=sum-mb[i].z2;
					swap(mc[nc],mb[i]);
					mc[nc].z2=mc[nc].z1-mc[nc].z2;
				}
			}
			if(na<=m && nb<=m && nc<=m){
				cout<<sum<<endl;
				continue;
			}
			else if(na>m){
				sort(ma+1,ma+1+na,cmp3);
				for(i=1;na-m>0;i++){
					na--;
					nc++;
					sum=sum-ma[i].z2;
				}
			}
			else{
				sort(mc+1,mc+1+nc,cmp3);
				for(i=1;nc-m>0;i++){
						nc--;
						nb++;
						sum=sum-mc[i].z2;
				}
			}
			cout<<sum<<endl;
			continue;
		}
		else{
			sort(mc+1,mc+1+nc,cmp1);
			
			for(i=1;nc-m>0;i++){
				nc--;
				if(mc[i].z2<mc[i].z1 || (mc[i].z2==mc[i].z1 && na<=nb)){
					na++;
					sum=sum-mc[i].z2;
					swap(ma[na],mc[i]);
					ma[na].z1=ma[na].z1-ma[na].z2;
				}
				else{
					nb++;
					sum=sum-mc[i].z1;
					swap(mb[nb],mc[i]);
					mb[nb].z1=mb[nb].z2-mb[nb].z1;
				}
			}
			if(na<=m && nb<=m && nc<=m){
				cout<<sum<<endl;
				continue;
			}
			else if(na>m){
				sort(ma+1,ma+1+na,cmp2);
				for(i=1;na-m>0;i++){
					na--;
					nb++;
					sum=sum-ma[i].z1;
				}
			}
			else{
				sort(mb+1,mb+1+nb,cmp2);
				for(i=1;nb-m>0;i++){
					nb--;
					na++;
					sum=sum-mb[i].z1;
				}
			}
			cout<<sum<<endl;
			continue;
		}
	}
	return 0;
}
