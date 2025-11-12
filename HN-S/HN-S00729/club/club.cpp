#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define ll long long
#define ull unsigned long long
#define Pii pair<int,int>
#define Pll pair<long long,long long> 
#define Endl "\n"
#define For(i,a,n) for(auto i=(a);i<=(n);i++)
#define FOR(i,n,a) for(auto i=(n);i>=(a);i--) 
using namespace std;
const int N=1e5+10,M=5005,Mod=1e9+7; 
mt19937 Rand(time(0));
int b[N],ans;
struct node{
	int id,v1,v2,v3,maxx,maxxid;
}a[N];
set<Pii>s;
void work(){
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	s.clear();
	ans=0;
	int n,a1=0,a2=0,a3=0;cin>>n;
	For(i,1,n){
		a[i].id=i;
		cin>>a[i].v1>>a[i].v2>>a[i].v3;
		a[i].maxx=max(max(a[i].maxx,a[i].v1),max(a[i].v2,a[i].v3));
		ans+=a[i].maxx;
	}
	sort(a+1,a+1+n,[](node x,node y){
		return Rand()%2; 
	});
	For(i,1,n){
		if(a[i].maxx==a[i].v1){
			a1++,a[i].maxxid=1;
		}
		if(a[i].maxx==a[i].v2){
			a2++,a[i].maxxid=2;
		}
		if(a[i].maxx==a[i].v3){
			a3++,a[i].maxxid=3;
		}
	}
	For(i,1,n){
		if(a[i].maxx==a[i].v1&&a[i].maxx==a[i].v2&&a[i].maxx==a[i].v3){
			if(a1<a2&a1<a3){
				a2--,a3--,a[i].maxxid=1;
			}
			else if(a2<a1&&a2<a3){
				a1--,a3--,a[i].maxxid=2;
			}
			else if(a3<a1&&a3<a2){
				a1--,a2--,a[i].maxxid=3;
			}
		}
		else if(a[i].maxx==a[i].v1&&a[i].maxx==a[i].v2){
			if(a1<a2){
				a2--,a[i].maxxid=1;
			}
			else{
				a1--,a[i].maxxid=2;
			}
		}
		else if(a[i].maxx==a[i].v2&&a[i].maxx==a[i].v3){
			if(a2<a3){
				a3--,a[i].maxxid=2;
			}
			else{
				a2--,a[i].maxxid=3;
			}
		}
		else if(a[i].maxx==a[i].v3&&a[i].maxx==a[i].v1){
			if(a1<a3){
				a3--,a[i].maxxid=1;
			}
			else{
				a1--,a[i].maxxid=3;
			}
		}
	}
	if(a1>n/2){
		int x=a1-(n/2);
		For(i,1,n){
			if(a[i].maxxid==1){
				s.insert({a[i].v1-max(a[i].v2,a[i].v3),i});
			}
		}
		int j=1;
		for(auto i:s){
			if(j>x)break;
			ans-=i.first;
			j++;
		}
	}
	else if(a2>n/2){
		int x=a2-(n/2);
		For(i,1,n){
			if(a[i].maxxid==2){
				s.insert({a[i].v2-max(a[i].v1,a[i].v3),i});
			}
		}
		int j=1;
		for(auto i:s){
			if(j>x)break;
			ans-=i.first;
			j++;
		}
	}
	else if(a3>n/2){
		int x=a3-(n/2);
		For(i,1,n){
			if(a[i].maxxid==3){
				s.insert({a[i].v3-max(a[i].v2,a[i].v1),i});
			}
		}
		int j=1;
		for(auto i:s){
			if(j>x)break;
			ans-=i.first;
			j++;
		}
	}
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int _;cin>>_;
	while(_--){
		work();
		cout<<endl;
	} 
	return 0;
} 
//密码：Ren5Jie4Di4Ling5% 
/*
T1一个半小时过，看错时间，于是匆匆忙忙给后三题写了个骗分代码。 
*/
