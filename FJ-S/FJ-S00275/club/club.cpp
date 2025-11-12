#include <bits/stdc++.h>
using namespace std;
int t,n,ac=1,bc=1,cc=1,sum=0;
struct myb{
	int a1;
	int b1;
	int c1;
}k[100010],a[100010],b[100010],c[100010];
void zuiai(int m){
	if(k[m].a1==max(max(k[m].a1,k[m].b1),k[m].c1)){
		a[ac]=k[m];
		ac++;
}	else if(k[m].b1==max(max(k[m].a1,k[m].b1),k[m].c1)){
		b[bc]=k[m];
		bc++;
}	else if(k[m].c1==max(max(k[m].a1,k[m].b1),k[m].c1)){
		c[cc]=k[m];
		cc++;
}
return ;
}
void cj(myb m){
	if(m.a1==max(max(m.a1,m.b1),m.c1)){
		a[ac]=m;
		ac++;
}	else if(m.b1==max(max(m.a1,m.b1),m.c1)){
		b[bc]=m;
		bc++;
}	else if(m.c1==max(max(m.a1,m.b1),m.c1)){
		c[cc]=m;
		cc++;
}
return ;
}
int dxc(myb x){
	if(x.a1>x.b1){
		if(x.a1>x.c1){
			return x.a1-max(x.b1,x.c1);
		}
		else return x.c1-x.a1;
	}
	else{
		if(x.b1>x.c1){
			return x.b1-max(x.a1,x.c1);
		}
		else return x.c1-x.b1;
	}
}
bool cmp(myb f1,myb f2){
	return dxc(f1)>dxc(f2);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int l=1;l<=t;l++){
		sum=0;
		ac=1;
		bc=1;
		cc=1;
		cin>>n;
		for(int j=1;j<=n;j++){
			scanf("%d",&k[j].a1);
			scanf("%d",&k[j].b1);
			scanf("%d",&k[j].c1);
			zuiai(j);
			//cout<<"t"<<endl;
		}
		sort(a+1,a+ac,cmp);
		//cout<<"t"<<endl;
		while(ac-1>(n/2)){
			ac--;
			a[ac].a1=-1;
			cj(a[ac]);
			//cout<<"ta"<<endl;
		}
		sort(b+1,b+bc,cmp);
		while(bc-1>(n/2)){
			bc--;
			b[bc].b1=-1;
			cj(b[bc]);
			//cout<<"tb"<<endl;
		}
		sort(c+1,c+cc,cmp);
		while(cc-1>(n/2)){
			cc--;
			c[cc].c1=-1;
			cj(c[cc]);
			//cout<<"tc"<<endl;
		}
		for(int i=1;i<ac;i++){
			sum+=a[i].a1;
		}
		for(int i=1;i<bc;i++){
			sum+=b[i].b1;
		}
		for(int i=1;i<cc;i++){
			sum+=c[i].c1;
		}
		cout<<sum<<endl;
		for(int i=0;i<=100010;i++){
			k[i].a1=0;
			a[i].a1=0;
			b[i].a1=0;
			c[i].a1=0;
			k[i].b1=0;
			a[i].b1=0;
			b[i].b1=0;
			c[i].b1=0;
			k[i].c1=0;
			a[i].c1=0;
			b[i].c1=0;
			c[i].c1=0;
		}
	}
	return 0;
}