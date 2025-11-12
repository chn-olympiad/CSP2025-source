#include<bits/stdc++.h>
using namespace std;
int bmrs[3]={0,0,0};int bmmy[3]={0,0,0};int rs;
int o;
struct bm{
	int bh;
	int bmqz;
};
struct stfp{
	int a;
	int b;
	int c;
	bm zt;
	bm czd;
	bm czx;
	bm xz;
};
bool cmpi(int a,int b){
	return a>b;
}
void fp(stfp &a){
	vector<int> l;
	l.push_back(a.a);
	l.push_back(a.b);
	l.push_back(a.c);
	sort(l.begin(),l.end(),cmpi);
	
		if(l[0]==a.a){
			a.zt.bh=1;
			a.zt.bmqz=l[0];
		}else if(l[0]==a.b){
			a.zt.bh=2;
			a.zt.bmqz=l[0];
		}else{
			a.zt.bh=3;
			a.zt.bmqz=l[0];
		}
		if(l[1]==a.a){
			a.czd.bh=1;
			a.czd.bmqz=l[1];
		}else if(l[1]==a.b){
			a.czd.bh=2;
			a.czd.bmqz=l[1];
		}else{
			a.czd.bh=3;
			a.czd.bmqz=l[1];
		}
		if(l[2]==a.a){
			a.czx.bh=1;
			a.czx.bmqz=l[2];
		}else if(l[1]==a.b){
			a.czx.bh=2;
			a.czx.bmqz=l[2];
		}else{
			a.czx.bh=3;
			a.czx.bmqz=l[2];
		}
	a.xz=a.zt;
}
bool cmp(stfp a,stfp b){
	return a.xz.bmqz>b.xz.bmqz;
}
bool xzpx(stfp a,stfp b){
	return a.xz.bmqz-a.czd.bmqz<b.xz.bmqz-b.czd.bmqz;
}
bool pd(stfp a,stfp b){
	return a.a==b.a &&a.b==b.b&&a.c==b.c&&(a.zt.bh==b.zt.bh &&a.xz.bh==b.xz.bh&&a.czd.bh==b.czd.bh&&a.czx.bh==b.czx.bh) &&(a.zt.bmqz==b.zt.bmqz &&a.xz.bmqz==b.xz.bmqz&&a.czd.bmqz==b.czd.bmqz&&a.czx.bmqz==b.czx.bmqz);
}
void bmcl(vector<stfp> &x,stfp l){
	vector<stfp> a;
	for(int i=0;i<x.size();i++){
		if(l.xz.bmqz>x[i].xz.bmqz-x[i].czd.bmqz){
			a.push_back(x[i]);
		}
	}
	if(!a.empty()){
		sort(a.begin(),a.end(),xzpx);
		for(int i=0;i<x.size();i++){
		if(pd(a[0],x[i])){
			bmmy[x[i].xz.bh-1]-=x[i].xz.bmqz;
			x[i].xz=x[i].czd;
			bmrs[x[i].xz.bh-1]+=1;
			bmmy[x[i].xz.bh-1]+=x[i].xz.bmqz;
			break;
		}
		}
		bmmy[l.czd.bh-1]+=l.xz.bmqz;
	}else{
		bmrs[l.czd.bh-1]+=1;
		bmmy[l.czd.bh-1]+=l.czd.bmqz;

	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
int h;
cin>>h;
for (int p=0;p<h;p++){
	int n;
	for(int mp=0;mp<3;mp++){
		bmrs[mp]=0;
		bmmy[mp]=0;
	}
	cin>>n;
	rs=n/2;
	vector<stfp> x;
	vector<stfp> t;
	stfp a;
	for(int i=0;i<n;i++){
		cin>>a.a>>a.b>>a.c;
		fp(a);
		x.push_back(a);
	}
	sort(x.begin(),x.end(),cmp);
	for(int i=0;i<n;i++){
		if(bmrs[x[i].xz.bh-1]<rs){
			bmrs[x[i].xz.bh-1]+=1;
			bmmy[x[i].xz.bh-1]+=x[i].xz.bmqz;
			t.push_back(x[i]);
		}else{
			bmcl(t,x[i]);
			t.push_back(x[i]);
		}
	}
	cout<<bmmy[0]+bmmy[1]+bmmy[2]<<"\n";
}
	return 0;
}
