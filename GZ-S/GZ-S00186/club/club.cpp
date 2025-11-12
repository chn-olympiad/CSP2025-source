//GZ-S00186 贵阳市第三实验中学 彭禹诺 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
map<ll,ll> ak;
ll te[3*N],n,m;
ll sum,k,ans,ki=0;
bool cmpa(ll x,ll y){
	return x>y;
}
struct S{
	ll fix,wi;
	int pos;
}p[3*N]; 
bool cmp(S x,S y){
	if(x.fix==y.fix){
		return x.wi<y.wi;
	}
	else {
		return x.fix>y.fix;
	}
}
void fun(ll i,ll mn,ll numq,ll numw,ll nume){
	if(i>m+1 || numq>n/2 || numw>n/2 || nume>n/2)return;
	ki=max(ki,mn);
	if(ak[p[i].pos]){
		fun(i+1,mn,numq,numw,nume);
	}
	else{
		if(p[i].wi==1){
			ak[p[i].pos]=1;
			fun(i+1,mn+p[i].fix,numq+1,numw,nume);
		}
		if(p[i].wi==2){
			ak[p[i].pos]=1;
			fun(i+1,mn+p[i].fix,numq,numw+1,nume);
		}
		if(p[i].wi==3){
			ak[p[i].pos]=1;
			fun(i+1,mn+p[i].fix,numq,numw,nume+1);
		}
		ak[p[i].pos]=0;
		fun(i+1,mn,numq,numw,nume);
    }	
}
void fun1(ll i,ll mn,ll numq,ll numw){
	if(i>m+1 || numq>n/2 || numw>n/2)return;
	ki=max(ki,mn);
	if(ak[p[i].pos]){
		fun1(i+1,mn,numq,numw);
	}
	else{
		if(p[i].wi==1){
			ak[p[i].pos]=1;
			fun1(i+1,mn+p[i].fix,numq+1,numw);
		}
		if(p[i].wi==2){
			ak[p[i].pos]=1;
			fun1(i+1,mn+p[i].fix,numq,numw+1);
		}
		ak[p[i].pos]=0;
		fun1(i+1,mn,numq,numw);
    }	
}
void init(){
	cin>>n;
	m=n*3;
	ll flagA=0,flagB=0,flagC=0,o=0;
	for(int i=1;i<=m;i+=3){
		cin>>p[i].fix>>p[i+1].fix>>p[i+2].fix;
		p[i].wi=1,p[i+1].wi=2,p[i+2].wi=3; 
		p[i].pos=i;p[i+1].pos=i;p[i+2].pos=i;
		
		flagA=max(flagA,p[i].fix); te[++o]=p[i].fix;
		flagB=max(flagB,p[i+1].fix);
		flagC=max(flagC,p[i+2].fix);
		ak[i]=0;
		
	}
	//特判A 
	if(flagA==0 && flagB==0 && flagC==0){
		cout<<0<<endl;
		return ;
	}
	if(flagB==0 && flagC==0){
		ll sum=0;
		sort(te+1,te+1+o,cmpa);
		for(int i=1;i<=n/2;i++)sum+=te[i];
		cout<<sum<<endl;
		return;
	}
	ll numa=0,numb=0,numc=0,num=0,k=n/2,sum=0,ans=0;
	sort(p+1,p+1+m,cmp);
	//性质B
	if(flagC==0){
		ki=0;
		fun1(1,0,0,0);
		cout<<ki<<endl;
		return;
	} 
	//30内
	if(n<=30){
		ki=0;
		fun(1,0,0,0,0);
		cout<<ki<<endl;
		return;
	} 
	for(int i=1;i<=m;i++){
		if(ak[p[i].pos])continue;
		if(num>=n-30){
			ki=0;
			fun(i,0,numa,numb,numc);
			break;
		}
		//if(num==n+1)break;
		if(p[i].wi==1 && numa<k){
			numa++;num++;
			sum+=p[i].fix;
			ak[p[i].pos]=1;
		}
		else if(p[i].wi==2 && numb<k){
			numb++;num++;
			sum+=p[i].fix;
			ak[p[i].pos]=1;
		}
		else if(p[i].wi==3 && numc<k){
			numc++;num++;
			sum+=p[i].fix;
			ak[p[i].pos]=1;
		}
	}
	cout<<sum+ki<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)init();
	return 0;
}
