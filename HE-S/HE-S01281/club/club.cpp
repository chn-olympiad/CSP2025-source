#include<bits/stdc++.h>
using namespace std;
struct like{
	int a,b,c;
}l[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,maxn[100010]={},num[3]={};
	cin>>t>>n;
	for(int i=0;i<t;i++){
		int sum=0;
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>l[j].a>>l[j].b>>l[j].c;
			maxn[j]=max(l[j].a,max(l[j].b,l[j].c));
			if(maxn[j]==l[j].a) num[1]++;
			else if(maxn[j]==l[j].b) num[2]++;
			else num[3]++;
			sum+=maxn[j];}
		int nummax=max(num[1],(num[2],num[3]));
		while(nummax*2>num[1]+num[2]+num[3]){
			int numf=0;
			if(nummax==num[1]) numf=1;
			else if(nummax==num[2]) numf=2;
			else numf=3;
			int minn=30000;
			int minflag=0;
			for(int i=0;i<n;i++){
				if(numf==1){
					if(l[i].a<minn){
						minn=l[i].a;
						minflag=i;}}
				else if(numf==2){
					if(l[i].b<minn){
						minn=l[i].b;
						minflag=i;}}
				else{if(l[i].c<minn){
						minn=l[i].c;
						minflag=i;}}}
			sum-=minn;
			if(numf==1) sum+=max(l[minflag].b,l[minflag].c);
			else if(numf==2) sum+=max(l[minflag].a,l[minflag].c);
			else sum+=max(l[minflag].b,l[minflag].a);}
		cout<<sum<<endl;	
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
