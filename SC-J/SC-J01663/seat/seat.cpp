#include <bits/stdc++.h>
using namespace std;
int sett[150][150],hs,ls;
struct inf{
	int gr;
	int ans;
}k[1005];
bool cmp(inf a,inf b){
	return a.gr>b.gr;
}
int f(int x){
	int p,yy;
	p=x/(hs*2);
	yy=x%(hs*2);
	if(yy>hs){
		return 2*p+2;
	}else if(yy<=hs&&yy!=0){
		return 2*p+1;
	}else{
		return 2*p;
	}
}
int g(int x){
	int p;
	p=x%hs;
	if(f(x)%2==0){
		if(p==0){
			return 1;
		}
		return hs-p+1;
	}else if(f(x)%2==1){
		if(p==0){
			return hs;
		}
		return p;
	}
	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>hs>>ls;
	cin>>k[1].gr;
	k[1].ans=1;
	for(int i=2;i<=hs*ls;i++){
		cin>>k[i].gr;
		k[i].ans=0;
	}
	sort(k+1,k+hs*ls,cmp);
//	for(int i=1;i<=hs*ls;i++){
//		cout<<k[i].gr<<endl;
//	}
	for(int i=1;i<=hs*ls;i++){
		if(k[i].ans==1){
			cout<<f(i)<<' '<<g(i);
			return 0;
		}
	}
	return 0;
} 