#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int T;
struct people{
	int a,b,c;
}val[N];
bool cmp1(people x,people y){
	if(x.a!=0) return false;
	if(y.a!=0) return true;
	if((x.b>=y.b&&x.b>=y.c)||(x.c>=y.b&&x.c>=y.c)){
		return true;
	}
	return false;
}
bool cmp2(people x,people y){
	if(x.b!=0) return false;
	if(y.b!=0) return true;
	if((x.a>=y.a&&x.a>=y.c)||(x.c>=y.a&&x.c>=y.c)){
		return true;
	}
	return false;
}
bool cmp3(people x,people y){
	if(x.c!=0) return false;
	if(y.c!=0) return true;
	if((x.b>=y.b&&x.b>=y.a)||(x.a>=y.b&&x.a>=y.a)){
		return true;
	}
	return false;
}
int n,numa,numb,numc;
int mem=0;
void clear(){
	for(int i=0;i<=mem+1;i++){
		val[i].a=val[i].b=val[i].c=0;
	}
	numa=numb=numc=0;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		clear();
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>val[i].a>>val[i].b>>val[i].c;
			if(val[i].a>=val[i].b&&val[i].a>=val[i].c){
				numa++;
				ans+=val[i].a;
				val[i].b=val[i].b-val[i].a;
				val[i].c=val[i].c-val[i].a;
				val[i].a=0;
			} 
			else if(val[i].b>=val[i].a&&val[i].b>=val[i].c){
				numb++;
				ans+=val[i].b;
				val[i].a=val[i].a-val[i].b;
				val[i].c=val[i].c-val[i].b;
				val[i].b=0;
			}
			else{
				numc++;
				ans+=val[i].c;
				val[i].a=val[i].a-val[i].c;
				val[i].b=val[i].b-val[i].c;
				val[i].c=0;
			}
		}
		if(numa>n/2){
			sort(val+1,val+1+n,cmp1);
			int cnt=0;
			while(numa>n/2){
				cnt++;
				ans+=(max(val[cnt].b,val[cnt].c));
				numa--;
			}
		}
		else if(numb>n/2){
			sort(val+1,val+1+n,cmp2);
			int cnt=0;
			while(numb>n/2){
				cnt++;
				ans+=(max(val[cnt].a,val[cnt].c));
				numb--;
			}
		}
		else if(numc>n/2){
			sort(val+1,val+1+n,cmp3);
			int cnt=0;
			while(numc>n/2){
				cnt++;
				ans+=(max(val[cnt].a,val[cnt].b));
				numc--;
			}
		}
		cout<<ans<<"\n";
		mem=n;
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


1
4
1 0 1000
2 0 100000
4 0 0
10 0 999
*/
