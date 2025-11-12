#include<bits/stdc++.h>
using namespace std;
long long t,n[50002],yi[100002],er[100002],san[100002];
long long q[3],p[3],cnt,all[3],o1,t1,s1;
long long xuan(int al,int x,int y, int z,int x1,int y1,int z1,int xyz){
	al=al+max(x,max(y,z));
	if(x==max(x,max(y,z))){
		x1++;
		if(x1>xyz){
			al=al-x;
		}
		else{
			return al;
		}
}

	if(y==max(x,max(y,z))){
		y1++;
		if(y1>xyz){
			al=al-y;
		}
		else{
			return al;
	}
}
	if(z==max(x,max(y,z))){
		z1++;
		if(z1>xyz){
			al=al-z;
		}
		else{
			return al;
		}
	}
	return al;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	for(long long i=1;i<=t;i++){
		scanf("%lld",&n[i]);
		for(long long j=1;j<=n[i];j++){
			scanf("%lld",&yi[j]);
			scanf("%lld",&er[j]);
			scanf("%lld",&san[j]);
		}
		cnt=n[i]/2;
		for(long long j=n[i];j>=1;j--){
			all[i]=xuan(all[i],yi[j],er[j],san[j],o1,t1,s1,cnt);
	}
	o1=0;
	t1=0;
	s1=0;
}

for(long long i=1;i<=t;i++){
	cout<<all[i]<<endl;
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
