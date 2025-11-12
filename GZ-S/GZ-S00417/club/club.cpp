//GZ-S00417 华东师范大学附属贵阳学校 谭斯雨
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct eg{
	int q,w,e,r,y;
}a[N];
int dp[N][4],ans,t,n;
bool cmp(eg d,eg f){
	return d.y<f.y;
}
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].q>>a[i].w>>a[i].e;
			int mx=max(a[i].q,max(a[i].w,a[i].e));
			if(a[i].q==mx){
				a[i].r=1;
			}
			else if(a[i].w==mx){
				a[i].r=2;
			}
			else if(a[i].e==mx){
				a[i].r=3;
			}
			int mi=min(a[i].q,min(a[i].w,a[i].e));
			ans+=mi;
			a[i].q-=mi;
			a[i].e-=mi;
			a[i].w-=mi;
			if(a[i].q==0){
				a[i].y=abs(a[i].e-a[i].w);
			}
			if(a[i].e==0){
				a[i].y=abs(a[i].q-a[i].w);
			}
			if(a[i].w==0){
				a[i].y=abs(a[i].e-a[i].q);
			}
		}
		sort(a+1,a+1+n,cmp);
		priority_queue<int,vector<int> ,greater<int> >a1,b1,c1;
		for(int i=1;i<=n;i++){
			if(a[i].r==1){
				a1.push(i);
			}
			if(a[i].r==2){
				b1.push(i);
			}
			if(a[i].r==3){
				c1.push(i);
			}
		}
		while(a1.size()>n/2){
			if(a[a1.top()].w!=0){
				b1.push(a1.top());
			}
			else{
				c1.push(a1.top());
			}
			a1.pop();
		}
		while(b1.size()>n/2){
			if(a[b1.top()].q!=0){
				a1.push(b1.top());
			}
			else{
				c1.push(b1.top());
			}
			b1.pop();
		}
		while(c1.size()>n/2){
			if(a[c1.top()].w!=0){
				b1.push(c1.top());
			}
			else{
				a1.push(c1.top());
			}
			c1.pop();
		}
		while(!a1.empty()){
			ans+=a[a1.top()].q;
			a1.pop();
		}
		while(!b1.empty()){
			ans+=a[b1.top()].w;
			b1.pop();
		}
		while(!c1.empty()){
			ans+=a[c1.top()].e;
			c1.pop();
		}
		cout<<ans<<endl;
	}
	return 0;
}//唯一会做的题，club我喜欢你，我不行了，只有这个题有测样例的必要哈（微笑）
