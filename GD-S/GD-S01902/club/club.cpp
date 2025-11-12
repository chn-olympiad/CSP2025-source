

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

#define ll long long
const ll maxn=20004;
ll t;
ll n;
ll half;
struct node{
	ll x,y,z;
};
vector <node> a;

void init(){
	const node f({0,0,0});
	
	for(int i=0;i<a.size();i++){
		a[i]=f;
	}
}

bool cmp(int x,int y){
	return x>y;
}
bool cmp1(node a,node b){
	return a.x>b.x;
}



void c1(){
	
	ll b[maxn];ll ans=0;
	if(a[0].x!=0){
		for(int i=0;i<n;i++){
			b[i]=a[i].x;
		}		
	}
	else if(a[0].y!=0){
		for(int i=0;i<n;i++){
			b[i]=a[i].y;
		}		
	}
	else{
		for(int i=0;i<n;i++){
			b[i]=a[i].z;
		}				
	}

	sort(b,b+n,cmp);
	for(int i=0;i<(n/2);i++){
		ans+=b[i];
	}
	cout<<ans<<endl;
}
void c2(){
	ll x[maxn];ll ans1=0,ans2=0,posx=0,posy=0;
	ll y[maxn];
	for(int i=0;i<n;i++){
		x[i]=a[i].x;
		y[i]=a[i].y;
	}
	sort(x,x+n,cmp);
	sort(y,y+n,cmp);
	vector <node> tmpx=a;
	vector <node> tmpy=a;
	vector <node> tmpz=a;
	sort(tmpx,tmpx+n-1,cmp1);
	for(int i=0;i<n;i++){
		if(x[i]>y[i] && posx<=n/2){
			ans1+=x[i];posx++;
		}
		else if(x[i]<y[i] && posy<=n/2){
			ans1+=y[i];posy++;
		}
		else if(x[i]=y[i]){
			ans1+=x[i];
		}
		else if(posx >n/2){
			ans1+=y[i];
			posy++;;
		}
		else if(posy>n/2){
			ans1+=x[i];
			posx++;
		}
	}

	cout<<ans1<<endl;
}
void c3(){
	cout<<111;
}

void check(){
	
	ll pos=0; ll ans;
	for(int i=0;i<n;i++){
		if((a[i].y==0 && a[i].z==0) || (a[i].y==0 && a[i].x==0) || (a[i].x==0 && a[i].z==0)){

			continue;
		}
		else{
	
			pos++;
		}
		if(pos!=0)break;
	}

	if(pos==0){

		c1();
		return;
	}
	pos=0;
	for(int i=0;i<n;i++){
		if(a[i].z!=0)pos++;
		if(pos!=0)break;
	}
	if(pos==0){
		c2();return;
	}
	else{
		c3();return;
	}
}



int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		half=n/2;
		init();
		for(int i=0;i<n;i++){
			node f;
			cin>>f.x>>f.y>>f.z;
			if(i>=a.size())a.push_back(f);
			else a[i]=f;

		}

		check();
		
	}
	
	
	return 0;
} 
