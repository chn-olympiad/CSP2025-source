#include<bits/stdc++.h>
using namespace std;
int T,n,k,Ans=0,ans=0,piggod;
struct DATA{
	int w,id,s;
	friend bool operator<(DATA a,DATA b){
		return a.w<b.w; 
	}
};
struct node{
	int w,id;
	friend bool operator<(node a,node b){
		return a.w>b.w; 
	}
}a[3][100001],c[3][100001];
bool b[100001];
void yi_tuo(){
	priority_queue<DATA>q;
		for(int i1,i2,i3,i=1;i<=n;i++){
			i1=c[0][i].w,i2=c[1][i].w,i3=c[2][i].w;
			q.push({i1,i,1}),q.push({i2,i,2}),q.push({i3,i,3});
		}
		memset(b,0,sizeof b);
		int s1=0,s2=0,s3=0;
		int m=0;
		while(!q.empty()){
			DATA j=q.top();
			q.pop();
			if(b[j.id]) continue;
			if((j.s==1 && s1==k)||(j.s==2 && s2==k)||(j.s==3 && s3==k)) continue;
			ans+=j.w;
			b[j.id]=1;
			if(j.s==1) s1++;
			else if(j.s==2) s2++;
			else s3++;
			m++;
			if(m==n) break;
		}
}
void perfect(){
	memset(b,0,sizeof b);
	for(int i=1;i<=n;i++){
		cin>>a[0][i].w>>a[1][i].w>>a[2][i].w;
		a[0][i].id=a[1][i].id=a[2][i].id=i;
	}
	for(int i=0;i<3;i++){
		memcpy(c[i],a[i],sizeof a[i]);
		sort(a[i]+1,a[i]+n+1);
	}
	int s1=0,s2=0,s0=0,m=0;
	for(int i1=1,i2=1,i0=1;i1<=n||i2<=n||i0<=n;){
		node a0=a[0][i0],a1=a[1][i1],a2=a[2][i2];
		if(b[a1.id]){i1++;continue;}
		if(b[a0.id]){i0++;continue;}
		if(b[a2.id]){i2++;continue;}
		if(a0.id==a1.id && s0!=k && s1!=k){
			if(a0.w-a[0][i0+1].w<a1.w-a[1][i1+1].w){
				Ans+=a1.w,b[a1.id]=1,s1++,i1++;
			}
			else{
				Ans+=a0.w,b[a0.id]=1,s0++,i0++;
			}
			m++;
		}
		else if(a2.id==a1.id && s2!=k && s1!=k){
			if(a2.w-a[0][i2+1].w<a1.w-a[1][i1+1].w){
				Ans+=a1.w,b[a1.id]=1,s1++,i1++;
			}
			else{
				Ans+=a2.w,b[a2.id]=1,s2++,i2++;
			}
			m++;
		}
		else if(a0.id==a2.id && s0!=k && s2!=k){
			if(a0.w-a[0][i0+1].w<a2.w-a[1][i2+1].w){
				Ans+=a2.w,b[a2.id]=1,s2++,i2++;
			}
			else{
				Ans+=a0.w,b[a0.id]=1,s0++,i0++;
			}
			m++;
		}
		else{
			if(a0.w>a1.w&&a0.w>a2.w) {Ans+=a0.w,b[a0.id]=1,s0++,i0++;}
			else if(a0.w<a1.w&&a0.w>a2.w) {Ans+=a1.w,b[a1.id]=1,s1++,i1++;}
			else {Ans+=a2.w,b[a2.id]=1,s2++,i2++;}
		}
	}
}
void hs(int i,int s1,int s2,int s3,int h){
	if(i==n+1){
		Ans=max(Ans,h);
		return;
	}
	if(s1!=k) hs(i+1,s1+1,s2,s3,h+a[0][i].w);
	if(s2!=k) hs(i+1,s1,s2+1,s3,h+a[1][i].w);
	if(s3!=k) hs(i+1,s1,s2,s3+1,h+a[2][i].w);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		k=n/2;
		Ans=0,ans=0,piggod=0;
		if(n>=30){
			perfect();
			yi_tuo();
			cout<<max(Ans,ans)<<'\n';
		}
		else{
			for(int i=1;i<=n;i++){
				cin>>a[0][i].w>>a[1][i].w>>a[2][i].w;
				piggod=max(piggod,max(a[0][i].w,max(a[1][i].w,a[2][i].w)));
			}
			hs(1,0,0,0,0);
			cout<<Ans<<'\n';
		}
	}
	return 0;
}
