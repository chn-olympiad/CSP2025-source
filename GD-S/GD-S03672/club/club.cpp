#include<bits/stdc++.h>
using namespace std;
long long T;
long long n;
struct Member{
	long long a,b,c;
}dat[100010];
long long datt[100010][3];
bool vis[100010];
//bool cmp(Member q,Member w){
//	return q.maxx>=w.maxx;
//}
//struct Satisfy{
//	long long num,man,val;
//};
//bool cmp2(Satisfy a,Satisfy b){
//	if(a.val!=b.val){
//		return a.val>b.val;
//	} 
//	if(a.man!=b.man){
//		return a.man<b.man;
//	}
//	return a.num<b.num;
//}
long long cnt[5];
long long dfsans=0;
void dfs(long long step,long long tot){
	if(step>n){
		dfsans=max(dfsans,tot);
		return;
	}
	for(long long i=0;i<3;i++){
		if(cnt[i]<n/2){
			cnt[i]++;
			dfs(step+1,tot+datt[step][i]);
			cnt[i]--; 
		}
	}
	return;
}
struct Student{
	long long num,val;
};
bool cmpStudent(Student a,Student b){
	return a.val>=b.val;
}
Student a[100010],b[100010],c[100010];
struct BFS{
	long long a,b,c,cur,ans;
};
//void bfs(){
//	queue <BFS> q;
//	q.push({0,0,0,0,0});
//	while(!q.empty()){
//		BFS b=q.front();
//		q.pop();
//		if(b.cur>n){
//			dfsans=max(dfsans,b.ans);
//			continue;
//		}
//		if(b.a<n/2){
//			q.push({b.a+1,b.b,b.c,b.cur+1,b.ans+dat[b.cur].a});
//		}if(b.b<n/2){
//			q.push({b.a,b.b+1,b.c,b.cur+1,b.ans+dat[b.cur].b});
//		}if(b.c<n/2){
//			q.push({b.a,b.b,b.c+1,b.cur+1,b.ans+dat[b.cur].c});
//		}
//	}
//	return;
//}
bool cmpa(Member aq,Member bq){//add q: sep from a,b
	return aq.a>=bq.a;
}
bool cmpmax(Member aq,Member bq){
	return max(aq.a,aq.b)>=max(bq.a,bq.b); 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//The teacher says that it can be used. Then it can be used.
	cin>>T;
	while(T--){
		cin>>n;
		set<long long> st,stt;
		for(long long i=1;i<=n;i++){
			vis[i]=false;
			cin>>dat[i].a>>dat[i].b>>dat[i].c;
			st.insert(dat[i].b);
			stt.insert(dat[i].c);
			datt[i][0]=dat[i].a;
			datt[i][1]=dat[i].b;
			datt[i][2]=dat[i].c;
			a[i].val=dat[i].a;
			b[i].val=dat[i].b;
			c[i].val=dat[i].c;
			a[i].num=b[i].num=c[i].num=i;
//			maxx=max(dat[i].a,max(dat[i].b,dat[i].c));
		}
		if(st.size()==1&&dat[1].b==0&&stt.size()==1&&dat[1].c==0){
			sort(dat+1,dat+n+1,cmpa);
			long long ans=0;
			for(long long i=1;i<=n/2;i++){
				ans+=dat[i].a;
			}
			cout<<ans<<endl;
			return 0;
		}else if(stt.size()==1&&dat[1].c==0){
			long long ans=0;
//			sort(dat+1,dat+n+1,cmpmax);
			sort(a+1,a+n+1,cmpStudent);
			sort(b+1,b+n+1,cmpStudent); 
			long long ansa=0,ansb=0;
			for(long long i=1;i<=n/2;i++){
				ansa+=a[i].val;
				ansb+=b[i].val;
			}
			for(long long i=n/2+1;i<=n;i++){
				ansa+=dat[a[i].num].b;
				ansb+=dat[b[i].num].a;
			}
			cout<<max(ansa,ansb)<<endl;
		} 
		if(n<=10){
			dfsans=0;
			dfs(1,0);
			cout<<dfsans<<endl;
			continue;
		}
//		dfsans=0;
//		bfs();
//		cout<<dfsans<<endl;
//		long long m=n/2;
//		long long cnt[5]={0,0,0,0,0},ans=0;
//		sort(dat+1,dat+n+1,cmp);
//		for(long long i=1;i<=n;i++){
//			
//		}
		
	}
	return 0;
}
