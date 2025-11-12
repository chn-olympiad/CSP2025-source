#include<bits/stdc++.h>
using namespace std;
struct Qe{
	int d[4],Mx,Mz,Md=0;
	bool meN;
} pt[100050];
int a,b,p[4];
bool cmp(Qe m,Qe n){
	return m.d[1]>n.d[1];
}
bool tmp(Qe m,Qe n){
	return m.d[2]>n.d[2];
}
bool bmp(Qe m,Qe n){
	return m.d[3]>n.d[3];
}
bool nmp(Qe m,Qe n){
	if(m.Md==n.Md)return m.d[m.Md]>n.d[n.Md];
	else return m.Md>n.Md;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out ","w",stdout);
	cin>>a;
	while(a--){
		int y=0;
		p[0]=0,p[1]=0,p[2]=0,p[3]=0;
		cin>>b;
		for(int i=1;i<=b;i++){
			cin>>pt[i].d[1]>>pt[i].d[2]>>pt[i].d[3];
			pt[i].meN=false;
		}
		sort(pt+1,pt+1+b,cmp);
		for(int i=1;i<=b;i++)pt[i].meN=true,pt[i].Md=1,pt[i].Mx=pt[i].d[1];
		sort(pt+1,pt+1+b,tmp);
		for(int i=1;i<=b;i++){
			if(pt[i].meN){
				if(pt[i].Mx<pt[i].d[2])pt[i].Md=2,pt[i].Mx=pt[i].d[2];
			}
			else pt[i].Md=2,pt[i].meN=true;
		}
		sort(pt+1,pt+1+b,bmp);
		for(int i=1;i<=b;i++){
			if(pt[i].meN){
				if(pt[i].Mx<pt[i].d[3])pt[i].Md=3,pt[i].Mx=pt[i].d[3];
			}
			else pt[i].Md=3,pt[i].meN=true;
		}
		sort(pt+1,pt+1+b,nmp);
		for(int i=1;i<=b;i++)p[pt[i].Md]++;
		for(int i=1;i<=3;i++){
			if(i==3)p[2]+=p[i];
			int t=1;
			if(p[i]>b/2){
				for(int j=p[i]-p[i-1];j>b/2;j--){
					if(t==i)t++;
					else if(p[t]<b/2)pt[j].Md=t;
					else t++;
				}
			}
		}
		for(int i=1;i<=b;i++)y+=pt[i].d[pt[i].Md];
		cout<<y<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
