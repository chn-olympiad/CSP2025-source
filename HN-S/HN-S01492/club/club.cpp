#include<bits/stdc++.h>//坏了优先队列。。。 不是我打了40分钟优先队列。。。 孩子们117行给自己看笑了 
using namespace std;
struct N{
	int a,b,c,id;
}a[100010];
struct Na{
	int a,b,c,id;
	friend operator <(Na x,Na y){
		return x.a-max(x.b,x.c)>y.a-max(y.b,y.c);
	}
};
struct Nb{
	int a,b,c,id;
	friend operator <(Nb x,Nb y){
		return x.b-max(x.a,x.c)>y.b-max(y.a,y.c);
	}
};
struct Nc{
	int a,b,c,id;
	friend operator <(Nc x,Nc y){
		return x.c-max(x.a,x.b)>y.c-max(y.b,y.a);
	}
};
bool cmp(N x,N y){
	return x.a+x.b+x.c<y.a+y.b+y.c;
}
Na work1_1(N x){Na cnt;cnt.a=x.a,cnt.b=x.b,cnt.c=x.c,cnt.id=x.id;return cnt;}
N work1_2(Na x){N cnt;cnt.a=x.a,cnt.b=x.b,cnt.c=x.c,cnt.id=x.id;return cnt;}
Nb work2_1(N x){Nb cnt;cnt.a=x.a,cnt.b=x.b,cnt.c=x.c,cnt.id=x.id;return cnt;}
N work2_2(Nb x){N cnt;cnt.a=x.a,cnt.b=x.b,cnt.c=x.c,cnt.id=x.id;return cnt;}
Nc work3_1(N x){Nc cnt;cnt.a=x.a,cnt.b=x.b,cnt.c=x.c,cnt.id=x.id;return cnt;}
N work3_2(Nc x){N cnt;cnt.a=x.a,cnt.b=x.b,cnt.c=x.c,cnt.id=x.id;return cnt;}
int n;
void solve(){
	cin>>n;
	queue<N>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		q.push(a[i]);
	}
	priority_queue<Na>qa;
	priority_queue<Nb>qb;
	priority_queue<Nc>qc;
	while(!q.empty()){
		N x=q.front();
		q.pop();
		if(x.a>=x.b && x.a>=x.c && x.a!=-1){
			if(qa.empty()){
				qa.push(work1_1(x));
			}else if(qa.size()<n/2){
				qa.push(work1_1(x));
			}else if(x.a+max(qa.top().b,qa.top().c)>qa.top().a+max(x.b,x.c) && x.a!=-1){
				q.push(work1_2(qa.top()));
				qa.pop();
				qa.push(work1_1(x));
			}else{
				x.a=-1;
				q.push(x);
			}
		}else if(x.b>=x.a && x.b>=x.c && x.b!=-1){
			if(qb.empty()){
				qb.push(work2_1(x));
			}else if(qb.size()<n/2){
				qb.push(work2_1(x));
			}else if(x.b+max(qb.top().a,qb.top().c)>qb.top().b+max(x.a,x.c)){
				q.push(work2_2(qb.top()));
				qb.pop();
				qb.push(work2_1(x));
			}else{
				x.b=-1;
				q.push(x);
			}
		}else if(x.c>=x.a && x.c>=x.b && x.c!=-1){
			if(qc.empty()){
				qc.push(work3_1(x));
			}else if(qc.size()<n/2){
				qc.push(work3_1(x));
			}else if(x.c+max(qc.top().a,qc.top().b)>qc.top().c+max(x.b,x.a)){
				q.push(work3_2(qc.top()));
				qc.pop();
				qc.push(work3_1(x));
			}else{
				x.c=-1;
				q.push(x);
			}
		}
	}
	long long ans=0;
	while(!qa.empty()){
		ans+=qa.top().a;
		qa.pop();
	}
	while(!qb.empty()){
		ans+=qb.top().b;
		qb.pop();
	}
	while(!qc.empty()){
		ans+=qc.top().c;
		qc.pop();
	}
	cout<<ans<<"\n";
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	} 
	return 0;
} 
