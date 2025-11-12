#include<bits/stdc++.h>
#define FILENAME "club"
using namespace std;
const int N=1e5+50;

int read(){
	int x=0,k=1;char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*k;
}

struct Node{
	int p1,p2,p3,sum,idx;
	bool operator <(Node d){
		return d.sum<sum;
	}
}a[N],cha[N];

int used[4];
int hit[4];

void cpm(int a,int b,int c,int x){
	int d=max(a,max(b,c));
	if(d==a){
		hit[1]++;
		cha[x].p1=0;
		cha[x].p2=a-b;
		cha[x].p3=a-c;
	}
	else if(d==b){
		hit[2]++;
		cha[x].p1=b-a;
		cha[x].p2=0;
		cha[x].p3=b-c;
	}else{
		hit[3]++;
		cha[x].p1=c-a;
		cha[x].p2=c-b;
		cha[x].p3=0;
	}
	//cha[x].sum=cha[x].p1+cha[x].p2+cha[x].p3;
	cha[x].idx=x;
}

int main(){
	freopen(FILENAME".in","r",stdin);
	freopen(FILENAME".out","w",stdout);
	int T=read();
	while(T--){
		memset(a,0,sizeof(a));
		memset(cha,0,sizeof(cha));
		memset(used,0,sizeof(used));
		memset(hit,0,sizeof(hit));
		
		//emptying
		int n=read();
		int up=n/2;
		int ans=0;
		for(int i=1;i<=n;i++){
			a[i].p1=read(),
			a[i].p2=read(),
			a[i].p3=read();
			//a[i].sum=a[i].p1+a[i].p2+a[i].p3;
			ans+=max(a[i].p1,max(a[i].p2,a[i].p3));
			
			cpm(a[i].p1,a[i].p2,a[i].p3,i);
			
			//cout<<cha[i].p1<<" "<<cha[i].p2<<" "<<cha[i].p3<<" "<<endl;
		}
		if(hit[1]<=up && hit[2]<=up && hit[3]<=up){
			cout<<ans<<"\n";
			continue;
		}
		
		int op=0,need=0,cul=0;
		if(hit[1]>up) op=1,need=hit[1]-up;
		else if(hit[2]>up) op=2,need=hit[2]-up;
		else if(hit[3]>up) op=3,need=hit[3]-up;
		
		priority_queue<int> q;
		for(int i=1;i<=n;i++){
			int k=0;
			if(op==1) k=cha[i].p1;
			else if(op==2) k=cha[i].p2;
			else k=cha[i].p3;
			if(k!=0) continue;
			
			if(op==1) k=min(cha[i].p2,cha[i].p3);
			else if(op==2) k=min(cha[i].p1,cha[i].p3);
			else k=min(cha[i].p1,cha[i].p2);
			
			if(q.size()<need) q.push(k);
			else if(q.top()>k){
				q.pop();q.push(k);	
			}
		}
		for(unsigned int i=0;i<need;i++){
			ans-=q.top();
			q.pop();
		}
		
		cout<<ans<<"\n";
	}
	return 0;
}

/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
