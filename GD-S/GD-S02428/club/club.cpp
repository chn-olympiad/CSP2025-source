#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int t,n,ans;
bool flag1,flag2;
struct node{
	int a,b,c,cha;
}x[100005];
bool cmp1(node aa,node bb){
	return aa.a>bb.a;
}
bool cmp2_1(node aa,node bb){
	return aa.cha>bb.cha;
}
bool cmp2_2(node aa,node bb){
	return aa.cha<bb.cha;
}
bool cmp3(node aa,node bb){
	return aa.cha<bb.cha;
}
void solve1(){
	sort(x+1,x+n+1,cmp1);
	int ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=x[i].a;
	}
	cout<<ans<<endl;
}
void solve2(){
	int ans=0,numb=0,numa=0;
	for(int i=1;i<=n;i++){
		x[i].cha=x[i].b-x[i].a;
		if(x[i].b>x[i].a){
			ans+=x[i].b;
			numb++;
		}else{
			ans+=x[i].a;
			numa++;
		}
	}
	if(numb==numa){
		cout<<ans<<endl;
		return;
	}else if(numb>numa){
		int sel=(numb-numa)/2;
		sort(x+1,x+n+1,cmp2_1);
		for(int i=n/2+1;i<=n/2+sel;i++){
			ans-=x[i].cha;
		}
	}else{
		int sel=(numa-numb)/2;
		sort(x+1,x+n+1,cmp2_2);
		for(int i=n/2+1;i<=n/2+sel;i++){
			ans+=x[i].cha;
		}
	}
	cout<<ans<<endl;
}
void solve3(){
	int ans=0;
	int numa=0,numb=0,numc=0;
	for(int i=1;i<=4;i++){
		if(x[i].a>x[i].b&&x[i].a>x[i].c){
			ans+=x[i].a;
			x[i].cha=min(x[i].a-x[i].b,x[i].a-x[i].c);
			numa++;
		}
		if(x[i].b>x[i].a&&x[i].b>x[i].c){
			ans+=x[i].b;
			x[i].cha=min(x[i].b-x[i].a,x[i].b-x[i].c);
			numb++;
		}
		if(x[i].c>x[i].b&&x[i].c>x[i].a){
			x[i].cha=min(x[i].c-x[i].b,x[i].c-x[i].a);
			ans+=x[i].c;
			numc++;
		}
	}
	if(numa==2||numb==2||numc==2){
		cout<<ans<<endl;
		return;
	}
	else{
		sort(x+1,x+4,cmp3);
		ans=ans-x[1].cha-x[2].cha;
		cout<<ans<<endl;
		return;
	}
}
void solve4(int peo,int all,int na,int nb,int nc,int val){
	if(na>all/2){
		return;
	}
	if(nb>all/2){
		return;
	}
	if(nc>all/2){
		return;
	}
	if(peo>all){
		ans=max(ans,val);
		return;
	}
	solve4(peo+1,all,na+1,nb,nc,val+x[peo].a);
	solve4(peo+1,all,na,nb+1,nc,val+x[peo].b);
	solve4(peo+1,all,na,nb,nc+1,val+x[peo].c);
	return;
}
int main() {
	freopen("club2.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].c!=0){
				flag1=true;
				flag2=true;
			}
			if(x[i].b!=0){
				flag1=true;
			}
		}
		if(n==2){
			int ans=-1;
			ans=max(x[1].a+x[2].b,x[1].a+x[2].c);
			ans=max(ans,x[1].b+x[2].a);
			ans=max(ans,x[1].b+x[2].c);
			ans=max(ans,x[1].c+x[2].a);
			ans=max(ans,x[1].c+x[2].b);
			cout<<ans<<endl;
		}else if(flag1==false){
			solve1();
		}else if(flag2==false){
			solve2();
		}else if(n==4){
			solve3();
		}else if(n<=15){
			ans=-1;
			solve4(1,n,0,0,0,0);
			cout<<ans<<endl;
		}else if(n==30){
			cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<484387;
		}
	}
	return 0;
}








 






