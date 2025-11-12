#include <bits/stdc++.h>
using namespace std;
int T;
int n;
struct SJ{
	int a,b,c,zy,id;
}sj[200005];
int mma,mmb,mmc,ans;
priority_queue<int> dl;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		mma=mmb=mmc=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>sj[i].a>>sj[i].b>>sj[i].c;
			sj[i].zy=max({sj[i].a,sj[i].b,sj[i].c});
			if(sj[i].zy==sj[i].a)mma++,sj[i].id=1;
			else{
				if(sj[i].zy==sj[i].b)mmb++,sj[i].id=2;
				else mmc++,sj[i].id=3;
			}
			ans+=sj[i].zy;
		}
		if(mma>n/2){
			for(int i=1;i<=n;i++){
				if(sj[i].id==1)dl.push(max(sj[i].b,sj[i].c)-sj[i].a);
			}
			while(mma>n/2){
				mma--;
				ans+=dl.top();
				dl.pop();
			}
		}
		if(mmb>n/2){
			for(int i=1;i<=n;i++){
				if(sj[i].id==2)dl.push(max(sj[i].a,sj[i].c)-sj[i].b);
			}
			while(mmb>n/2){
				mmb--;
				ans+=dl.top();
				dl.pop();
			}
		}
		if(mmc>n/2){
			for(int i=1;i<=n;i++){
				if(sj[i].id==3)dl.push(max(sj[i].a,sj[i].b)-sj[i].c);
			}
			while(mmc>n/2){
				mmc--;
				ans+=dl.top();
				dl.pop();
			}
		}
		while(!dl.empty()){
			dl.pop();
		}
		cout<<ans<<'\n';
	}
	return 0;
}
