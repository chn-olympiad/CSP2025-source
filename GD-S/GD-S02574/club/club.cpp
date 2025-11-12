#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

struct nod{
	ll a,b,c;
};

int n;
nod x[N];
nod a[N],b[N],c[N];
int topa,topb,topc;
ll ans;

ll maxx(nod x){
	ll k=0;
//	if(x.a>x.b&&x.a>x.c)k=x.a;
//	else{
//		if(x.b>x.a&&x.b>x.c)k=x.b;
//		else k=x.c/*,cout<<"hi"<<endl*/;
//	}
////	else if(x.c>x.a&&x.c>x.b);
//	if(k==0)cout<<"Wrong"<<" "<<x.a<<" "<<x.b<<" "<<x.c<<" "<<endl;
//	if(k==0)k=x.c;
	
	k=max(x.a,max(x.b,x.c));
	return k;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool cmpa(nod x,nod y){
	return min(x.a-x.b,x.a-x.c)>min(y.a-y.b,y.a-y.c); 
}

void sorta(){
	sort(a+1,a+topa+1,cmpa);
	while(topa>n/2){
		if(a[topa].b>a[topa].c){
			topb++;
			b[topb]=a[topa];
			a[topa]={0,0,0};
			topa--;
		}else{
			topc++;
			c[topc]=a[topa];
			a[topa]={0,0,0};
			topa--;
		}
	}
	return ;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool cmpb(nod x,nod y){
	return min(x.b-x.a,x.b-x.c)>min(y.b-y.a,y.b-y.c); 
}

void sortb(){
	sort(b+1,b+topb+1,cmpb);
//	
//	cout<<"bbb"<<endl;
//	for(ll i=1;i<=topb;i++){
//		cout<<b[i].a<<" "<<b[i].b<<" "<<b[i].c<<endl;
//	}
//	
	while(topb>n/2){
		if(b[topb].a>b[topb].c){
			topa++;
			a[topa]=b[topb];
			b[topb]={0,0,0};
			topb--;
		}else{
//			cout<<"BBB "<<topb<<" "<<b[topb].a<<" "<<b[topb].b<<" "<<b[topb].c<<endl;
//			
			topc++;
			c[topc]=b[topb];
//			
//			cout<<"ccc "<<topc<<" "<<c[topc].a<<" "<<c[topc].b<<" "<<c[topc].c<<endl;
//			
			b[topb]={0,0,0};
			topb--;
		}
	}
	return ;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool cmpc(nod x,nod y){
	return min(x.c-x.a,x.c-x.b)>min(y.c-y.a,y.c-y.b); 
}

void sortc(){
	sort(c+1,c+topc+1,cmpc);
	while(topc>n/2){
		if(c[topc].a>c[topc].b){
			topa++;
			a[topa]=c[topc];
			c[topc]={0,0,0};
			topc--;
		}else{
			topb++;
			b[topb]=c[topc];
			c[topc]={0,0,0};
			topc--;
		}
	}
	return ;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void summ(){
	for(ll i=1;i<=topa;i++)ans+=a[i].a;
	for(ll i=1;i<=topb;i++)ans+=b[i].b;
	for(ll i=1;i<=topc;i++)ans+=c[i].c;
	return ;
}

void checkk(){
	cout<<endl;
	cout<<"a"<<endl;
	for(ll i=1;i<=topa;i++){
		cout<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<endl;
	}
	cout<<"b"<<endl;
	for(ll i=1;i<=topb;i++){
		cout<<b[i].a<<" "<<b[i].b<<" "<<b[i].c<<endl;
	}
	cout<<"c"<<endl;
	for(ll i=1;i<=topc;i++){
		cout<<c[i].a<<" "<<c[i].b<<" "<<c[i].c<<endl;
	}
	cout<<endl;
	return ;
}

void workk(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>x[i].a>>x[i].b>>x[i].c;
	}
	for(ll i=1;i<=n;i++){
		if(maxx(x[i])==x[i].a)a[++topa]=x[i];
		else{
			if(maxx(x[i])==x[i].b)b[++topb]=x[i];
			else c[++topc]=x[i];
		}
	}
//	
//	checkk();
	
	if(topa>n/2)sorta();
	if(topb>n/2)sortb();
	if(topc>n/2)sortc();
	
//	
//	checkk();
	
	summ();
	
//	
//	checkk();
	
	cout<<ans<<endl;
//	if(topa>n/2||topb>n/2||topc>n/2)cout<<"Wrong"<<endl;
	
	for(ll i=1;i<=n;i++)x[i]={0,0,0};
	for(ll i=1;i<=topa;i++)a[i]={0,0,0};
	for(ll i=1;i<=topb;i++)b[i]={0,0,0};
	for(ll i=1;i<=topc;i++)c[i]={0,0,0};
	topa=topb=topc=ans=0;
	return ;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ll T;
	cin>>T;
	while(T--){
		workk();
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0 
0 2 0
2
10 9 8
4 0 0 

18
4
13
*/
