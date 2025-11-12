#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int p1=0,p2=0,p3=0;
int now=0;
struct g{
	int a1,a2,a3;
	int ma,ma_mi;
}good[100000];
bool cmp(const g &a,const g&b){
	int fir=max(max(p1,p2),max(p3,p2)),fid;
	if(fir==p1) fid=1;
	else if(fir==p2) fid=2;
	else fid=3;
	if(a.ma==fid){
		if(b.ma==fid){
			return a.ma_mi>b.ma_mi;
		}
		else{
			return 0;
		}
	}
	else{
		if(b.ma==fid){
			return 1;
		}
		else{
			return 0;
		}
	}
}
void _init(){
	cin>>t;
	for(int j=0;j<t;j++){
		memset(good,0,sizeof(good));
		p1=0;p2=0;p3=0;now=0;n=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cout<<good[i].a1<<good[i].a2<<good[i].a3;
			good[i].ma=max(max(good[i].a1,good[i].a2),max(good[i].a3,good[i].a2));
			good[i].ma_mi=good[i].ma-min(max(good[i].a1,good[i].a2),max(good[i].a3,good[i].a2));
			if(good[i].ma==p1) p1++; 
			else if(good[i].ma==p2) p2++;
			else p3++;
			now+=good[i].ma;
		}
		sort(good,good+n,cmp);
		int fir=max(max(p1,p2),max(p3,p2));
		int tmp=0;
		while(fir>n/2){
			fir--;
			now-=good[tmp++].ma_mi;
		}
		cout<<now;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
