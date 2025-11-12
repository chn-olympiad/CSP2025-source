#include<bits/stdc++.h>
using namespace std;
long long zn,zm,zk,zu[1000001],zv[1000001],zw[1000001],zc[11],za[11][1001],xs[4000041],jt[4000041];
long long zs,dqd,jg,dqb,xt[1000011],mb[2200021],bq[2200021],lb[2200021],bs,bx,jl[11],da,yj[1200011];
bool gx,yf,bj[1000011];
void js(long long kt,long long jw,long long bh){
	if(kt==jw){
		xs[bh]=4000000000000000000;
		jt[bh]=kt;
		yj[kt]=xs[bh];
		return;
	}
	js(kt,(kt+jw)/2,bh*2);
	js((kt+jw)/2+1,jw,bh*2+1);
	xs[bh]=4000000000000000000;
	jt[bh]=kt;
	return;
}
void xg(long long kt,long long jw,long long mb,long long sz,long long bh){
	if(kt==jw){
		xs[bh]=sz;
		yj[kt]=xs[bh];
		return;
	}
	if(mb<=(kt+jw)/2){
		xg(kt,(kt+jw)/2,mb,sz,bh*2);
	}
	else{
		xg((kt+jw)/2+1,jw,mb,sz,bh*2+1);
	}
	if(xs[bh*2]<xs[bh*2+1]){
		xs[bh]=xs[bh*2];
		jt[bh]=jt[bh*2];
	}
	else{
		xs[bh]=xs[bh*2+1];
		jt[bh]=jt[bh*2+1];
	}
	return;
}
void sc(long long kt,long long jw,long long mb,long long sz,long long bh){
	if(kt==jw){
		xs[bh]=sz;
		yj[kt]=xs[bh];
		return;
	}
	if(mb<=(kt+jw)/2){
		sc(kt,(kt+jw)/2,mb,sz,bh*2);
	}
	else{
		sc((kt+jw)/2+1,jw,mb,sz,bh*2+1);
	}
	if(xs[bh*2]<xs[bh*2+1]){
		xs[bh]=xs[bh*2];
		jt[bh]=jt[bh*2];
	}
	else{
		xs[bh]=xs[bh*2+1];
		jt[bh]=jt[bh*2+1];
	}
	return;
}
void primsf(){
	js(1,zs,1);
//cout<<"^^^"<<endl;
	if(0<yj[1]){
		xg(1,zs,1,0,1);
	}
//cout<<"AAA"<<endl;
	for(int i=1;i<=zs-bx;i++){
//cout<<i<<">"<<endl;
//if(i%100==0){
//	cout<<i<<endl;
//}
		dqd=jt[1];
		jg+=xs[1];
//cout<<jt[1]<<"   "<<xs[1]<<endl;
		sc(1,zs,dqd,4000000000000000000,1);
		bj[dqd]=1;
		dqb=xt[dqd];
//cout<<"CCC"<<endl;
		while(dqb!=0){
//cout<<"_______"<<dqb<<"   "<<mb[dqb]<<endl;
			if(bj[mb[dqb]]==0){
//cout<<"KKK"<<endl;
				if(bq[dqb]<yj[mb[dqb]]){
//cout<<"VVV"<<endl;
					xg(1,zs,mb[dqb],bq[dqb],1);
//cout<<"!!!"<<endl;
				}
			}
			dqb=lb[dqb];
		}
//cout<<"III"<<endl;
	}
	return;
}
void tb(long long kt,long long jw,long long hf){
	bs++;
	lb[bs]=xt[kt];
	mb[bs]=jw;
	bq[bs]=hf;
	xt[kt]=bs;
	return;
}
void mj(long long bh){
	if(bh==zk+1){
		for(int i=1;i<=zs;i++){
			bj[i]=0;
		}
		jg=0;
		bx=zk;
		for(int i=1;i<=zk;i++){
			if(jl[i]==0){
				bj[zn+i]=0;
				jg+=zc[i];
				bx--;
			}
			else{
				bj[zn+i]=1;
			}
		}
//cout<<"******************"<<endl;
		primsf();
		da=min(da,jg);
//cout<<"=================="<<jg<<endl;
		return;
	}
	jl[bh]=0;
	mj(bh+1);
	jl[bh]=1;
	mj(bh+1);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>zn>>zm>>zk;
	for(int i=1;i<=zm;i++){
		cin>>zu[i]>>zv[i]>>zw[i];
		tb(zu[i],zv[i],zw[i]);
		tb(zv[i],zu[i],zw[i]);
	}
	gx=1;
	for(int i=1;i<=zk;i++){
		cin>>zc[i];
		if(zc[i]!=0){
			gx=0;
		}
		yf=0;
		for(int j=1;j<=zn;j++){
			cin>>za[i][j];
			tb(zn+i,j,za[i][j]);
			tb(j,zn+i,za[i][j]);
			if(za[i][j]==0){
				yf=1;
			}
		}
		if(yf==0){
			gx=0;
		}
	}
	zs=zn+zk;
//cout<<"---------"<<endl;
//for(int i=1;i<=bs;i++){
//	cout<<mb[i]<<"   "<<bq[i]<<endl;
//}
//cout<<"----------"<<endl;
	if(gx==1){
		primsf();
		cout<<jg<<endl;
	}
	else{
//cout<<":::::::::::::::::"<<endl;
		da=4000000000000000000;
		mj(1);
		cout<<da<<endl;
	}
//cout<<"???";
	return 0;
}
