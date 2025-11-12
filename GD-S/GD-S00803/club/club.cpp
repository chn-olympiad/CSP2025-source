#include<bits/stdc++.h>
using namespace std;
#define int long long
struct str{
	int mo[4];
}a[100005];
int t,n,mmy,my[4],want[100005];
bool f1(str x){
	return x.mo[1]>x.mo[2];
}
bool f2(str x){
	return x.mo[1]>x.mo[3];
}
bool f3(str x){
	return x.mo[2]>x.mo[3];
}
bool g1(){
	return my[1]>my[2];
}
bool g2(){
	return my[1]>my[3];
}
bool g3(){
	return my[2]>my[3];
}
int hope(str x){
	if(f1(x)&&f2(x)){
		return 1;
	}
	if(!f1(x)&&f3(x)){
		return 2;
	}
	return 3;
}
int hate(str x){
	if(!f1(x)&&!f2(x)){
		return 1;
	}
	if(f1(x)&&!f3(x)){
		return 2;
	}
	return 3;
}
int well(str x){
	return 6-hope(x)-hate(x);
}
int love(){
	if(g1()&&g2()){
		return 1;
	}
	if(!g1()&&g3()){
		return 2;
	}
	return 3;
}
bool younique(str x,str y){
	if(hope(x)^mmy){
		return 0;
	}
	if(hope(y)^mmy){
		return 1;
	}
	return x.mo[mmy]-x.mo[well(x)]<y.mo[mmy]-y.mo[well(y)];
}
int justdoit(){
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i].mo[want[i]];
	}
	return ans;
}
int mian(){
	memset(my,0,sizeof(my));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].mo[1]>>a[i].mo[2]>>a[i].mo[3];
		my[hope(a[i])]++;
	}
	mmy=love();
	if(my[mmy]>n/2){
		sort(a+1,a+n+1,younique);
		for(int i=1;i<=n;i++){
			if(i<=my[mmy]-n/2){
				want[i]=well(a[i]);
			}else{
				want[i]=hope(a[i]);
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			want[i]=hope(a[i]);
		}
	}
	cout<<justdoit()<<"\n"; 
	return 0;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		mian();
	}
	return 0;
}
