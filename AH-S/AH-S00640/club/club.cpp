//no more segtree pls
//not dp good ccf
//pls make this ac orz
//ohno my code is cooked :(
//goodbye c++ i will miss u
#include<bits/stdc++.h>
using namespace std;
const int mxn=200030;
int t;
struct stu{
	int a,b,c;
	int mxpos,curpos;
};
struct chafen{
	int ch,id,pos;
};
stu st[mxn];
chafen ch[3*mxn];
int n,ans=0;
int cura=0,curb=0,curc=0;
bool bichafen(chafen x,chafen y){
	return x.pos<=y.pos;
}
void solve(){//1->a|2->b|3->c
	ans=cura=curb=curc=0;
	for(int i=1;i<=mxn;i++){st[i].a=st[i].b=st[i].c=st[i].curpos=ch[i].ch=ch[i].id=ch[i].pos=0;}
	cin>>n;
	if(n==2){
		for(int i=1;i<=n;i++){
			cin>>st[i].a>>st[i].b>>st[i].c;
		}
		int mxans=-1;
		mxans=max(mxans,st[1].a+st[2].b);
		mxans=max(mxans,st[1].a+st[2].c);
		mxans=max(mxans,st[1].b+st[2].a);
		mxans=max(mxans,st[1].b+st[2].c);
		mxans=max(mxans,st[1].c+st[2].a);
		mxans=max(mxans,st[1].c+st[2].b);
		cout<<mxans<<endl;
		return ;
	}
	int pp=1;
	for(int i=1;i<=mxn;i++) ch[i].ch=ch[i].id=ch[i].pos=1e7;
	for(int i=1;i<=n;i++){
		cin>>st[i].a>>st[i].b>>st[i].c;
		int mx=max(max(st[i].a,st[i].b),st[i].c);
		ans+=mx;
		if(mx==st[i].a){
			cura++,st[i].mxpos=st[i].curpos=1;
			ch[pp].ch=mx-st[i].b,ch[pp].id=i,ch[pp].pos=2,pp++;
			ch[pp].ch=mx-st[i].c,ch[pp].id=i,ch[pp].pos=3,pp++;
		}
		else if(mx==st[i].b){
			curb++,st[i].mxpos=st[i].curpos=2;
			ch[pp].ch=mx-st[i].a,ch[pp].id=i,ch[pp].pos=1,pp++;
			ch[pp].ch=mx-st[i].c,ch[pp].id=i,ch[pp].pos=3,pp++;
		}
		else{
			curc++,st[i].mxpos=st[i].curpos=3;
			ch[pp].ch=mx-st[i].a,ch[pp].id=i,ch[pp].pos=1,pp++;
			ch[pp].ch=mx-st[i].b,ch[pp].id=i,ch[pp].pos=2,pp++;
		}
	}
	sort(ch+1,ch+1+2*n,bichafen);
	int pt=1,mans=0;
	while(cura>n/2||curb>n/2||curc>n/2){
		if(pt>2*n+1) break;
		chafen curch=ch[pt];
		if(st[curch.id].curpos==1) cura--;
		else if(st[curch.id].curpos==2) curb--;
		else if(st[curch.id].curpos==3) curc--;
		if(curch.pos==1) cura++;
		else if(curch.pos==2) curb++;
		else if(curch.pos==3) curc++;
		st[curch.id].curpos=curch.pos;
		pt++;
		/*if(st[curch.id].curpos==1){
			cura--;
			if(curch.pos==1) cura++;
			else if(curch.pos==2){
				ans+=st[curch.id].b,curb++;
				if(st[curch.id].curpos==1) ans-=st[curch.id].a;
				else if(st[curch.id].curpos==2) ans-=st[curch.id].b;
				else if(st[curch.id].curpos==3) ans-=st[curch.id].c;
			}
			else if(curch.pos==3){
				ans=ans+st[curch.id].c,curc++;
				if(st[curch.id].curpos==1) ans-=st[curch.id].a;
				else if(st[curch.id].curpos==2) ans-=st[curch.id].b;
				else if(st[curch.id].curpos==3) ans-=st[curch.id].c;
			}
		} 
		if(st[curch.id].curpos==2){
			curb--;
			if(curch.pos==1){
				ans=ans+st[curch.id].a,cura++;
				if(st[curch.id].curpos==1) ans-=st[curch.id].a;
				else if(st[curch.id].curpos==2) ans-=st[curch.id].b;
				else if(st[curch.id].curpos==3) ans-=st[curch.id].c;
			}
			else if(curch.pos==2) curb++;
			else if(curch.pos==3){
				ans=ans+st[curch.id].c,curc++;
				if(st[curch.id].curpos==1) ans-=st[curch.id].a;
				else if(st[curch.id].curpos==2) ans-=st[curch.id].b;
				else if(st[curch.id].curpos==3) ans-=st[curch.id].c;
			}
		} 
		if(st[curch.id].curpos==3){
			curc--;
			if(curch.pos==1){
				ans=ans+st[curch.id].a,cura++;
				if(st[curch.id].curpos==1) ans-=st[curch.id].a;
				else if(st[curch.id].curpos==2) ans-=st[curch.id].b;
				else if(st[curch.id].curpos==3) ans-=st[curch.id].c;
			}
			else if(curch.pos==2){
				ans=ans+st[curch.id].b,curb++;
				if(st[curch.id].curpos==1) ans-=st[curch.id].a;
				else if(st[curch.id].curpos==2) ans-=st[curch.id].b;
				else if(st[curch.id].curpos==3) ans-=st[curch.id].c;
			}
			else if(curch.pos==3) curc++;
		}
		pt++;*/
	}
	for(int i=1;i<=n;i++){
		if(st[i].curpos==1) mans+=st[i].a;
		else if(st[i].curpos==2) mans+=st[i].b;
		else if(st[i].curpos==3) mans+=st[i].c;
	}
	cout<<mans<<endl;
//	cout<<ans<<endl;
	return; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--) solve();
	return 0;
}
//thank you c++
//you give me the best memories in my aoharu
//i will be back and become BETTER
//so please wait for me...
