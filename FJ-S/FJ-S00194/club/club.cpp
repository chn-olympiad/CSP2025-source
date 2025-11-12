#include <bits/stdc++.h>
using namespace std;
int t;//×éÊý
bool css[1000010];
bool scs[1000010];
bool csc[1000010];
bool ssc[1000010];
bool scc[1000010];
int a1[1000010];
int a2[1000010];
int a3[1000010];
int v=1;
int vv=1;
int vvv=1;
int n;
struct mc{
	int xq;
	int xa;
	int sz;
};
mc d[3000010];
bool cmd(mc a,mc b){
	if (a.xa<0)a.xa*=-1;
	if (b.xa<0)a.xa*=-1;
	return a.xa>b.xa;
}
int cz(){
	int ans=0;
	sort(d+1,d+1+n,cmd);
	mc dd[100010];
	mc bx[100010];
	for(int i2=1;i2<=v;i2++){
		if(!css[d[i2].sz]){
			css[d[i2].sz]=1;
			dd[vv].xq=d[i2].xq;
			dd[vv].xa=d[i2].xa;
			dd[vv].sz=d[i2].sz;
			vv++;
		}else{
			if(!scs[d[i2].sz]){
				scs[d[i2].sz]=1;
				bx[vvv].xq=d[i2].xq;
				bx[vvv].xa=d[i2].xa;
				bx[vvv].sz=d[i2].sz;
				vvv++;
			}
		}
	}
	int f1[4],f=int(n/2);
	f1[1]=1;
	f1[2]=1;
	f1[3]=1;
	for(int i=1;i<=vv;i++){
		if (dd[i].xq==1){
			if (dd[i].xq>0){
				if((f1[1]+1)<=f)ans += a1[dd[i].sz];csc[dd[i].sz]=1;f1[1]++; //a
			}else{
				if((f1[2]+1)<=f)ans += a2[dd[i].sz];csc[dd[i].sz]=1;f1[2]++;//b
			}
		}else if (dd[i].xq==2){
			if (dd[i].xq>0){
				if((f1[1]+1)<=f)ans += a1[dd[i].sz];csc[dd[i].sz]=1;f1[1]++;//a
			}else{
				if((f1[2]+1)<=f)ans += a3[dd[i].sz];csc[dd[i].sz]=1;f1[3]++;//c
			}
		}else{
			if (dd[i].xq>0){
				if((f1[2]+1)<=f)ans += a2[dd[i].sz];csc[dd[i].sz]=1;f1[2]++;//b
			}else{
				if((f1[3]+1)<=f)ans += a3[dd[i].sz];csc[dd[i].sz]=1;f1[3]++;//c
			}			
		}
	}
	for(int i=1;i<=vvv;i++){
		if(!csc[i]){
			if (bx[i].xq==1){
				if (bx[i].xq>0){
					if((f1[1]+1)<=f)ans += a1[bx[i].sz];scc[bx[i].sz]=1;f1[1]++; //a
				}else{
					if((f1[2]+1)<=f)ans += a2[bx[i].sz];scc[bx[i].sz]=1;f1[2]++;//b
				}
			}else if (bx[i].xq==2){
				if (bx[i].xq>0){
					if((f1[1]+1)<=f)ans += a1[bx[i].sz];scc[bx[i].sz]=1;f1[1]++;//a
				}else{
					if((f1[3]+1)<=f)ans += a3[bx[i].sz];scc[bx[i].sz]=1;f1[3]++;//c
				}
			}else{
				if (bx[i].xq>0){
					if((f1[2]+1)<=f)ans += a2[bx[i].sz];scc[bx[i].sz]=1;f1[2]++;//b
				}else{
					if((f1[3]+1)<=f)ans += a3[bx[i].sz];scc[bx[i].sz]=1;f1[3]++;//c
				}			
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!scc[i]){
			if((f1[1]+1)<=f)ans+=a1[i];
			if((f1[2]+1)<=f)ans+=a2[i];
			if((f1[3]+1)<=f)ans+=a3[i];
		}
	}
	return ans;
}
int ry(){
	cin >> n;
	for(int i=1;i<=n;i++){
		int aa,bb,cc;
		cin >> aa;
		cin >> bb;
		cin >> cc;
		aa = a1[i];
		bb = a2[i];
		cc = a3[i];
		d[v].xq=1;
		d[v].xa=aa-bb;
		d[v].sz=i;
		v++;
		d[v].xq=2;
		d[v].xa=aa-cc;
		d[v].sz=i;
		v++;
		d[v].xq=3;
		d[v].xa=bb-cc;
		d[v].sz=i;
		v++;
	}
	return cz();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t; 
	for(int i=1;i<=t;i++){
		cout << ry() << endl;
	}
	return 0;
}
