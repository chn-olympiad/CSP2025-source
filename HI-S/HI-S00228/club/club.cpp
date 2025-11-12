#include <bits/stdc++.h>
using namespace std;
struct stu{
	int f;
	int s;
	int t;
};
stu a[100000];
stu fa[100000];
stu sma[100000];
stu tma[100000];
bool cmp1(stu x,stu y){
	if(x.f==y.f) return x.s+x.t<y.s+y.t;
	return x.f>y.f;
}
bool cmp2(stu x,stu y){
	if(x.s==y.s) return x.f+x.t<y.f+y.t;
	return x.s>y.s;
}
bool cmp3(stu x,stu y){
	if(x.t==y.t) return x.f+x.s<y.f+y.s;
	return x.t>y.t;
}
stack<stu> first;
stack<stu> second;
stack<stu> third;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	while(t--){
		long long t,fm=0,sm=0,tm=0,half,s=0,j=0,b[1000];
		int n,k=0;
		cin>>n;
		half=n/2;
		for(int i=0;i<n;i++){//输入并存入对应数组 
			scanf("%d %d %d",&a[i].f,&a[i].s,&a[i].t);
			if(a[i].f >= a[i].s && a[i].f >= a[i].t){
				fa[fm++]=a[i];	
				s+=a[i].f;
			}
			else if(a[i].s > a[i].f && a[i].s >= a[i].t){
				sma[sm++]=a[i];
				s+=a[i].s;
			}
			else{
				tma[tm++]=a[i];
				s+=a[i].t;
			}
		}
		if(1){//对数组排序并压栈 
		sort(fa,fa+fm,cmp1);
		sort(sma,sma+sm,cmp2);
		sort(tma,tma+tm,cmp3);
		for(int i=0;i<fm;i++) first.push(fa[i]);
		for(int i=0;i<sm;i++) second.push(sma[i]);
		for(int i=0;i<tm;i++) third.push(tma[i]);
		}		
		if(first.size()>half&&second.size()<=half&&third.size()<=half){//first大于 
			while(first.size()>half){
			stu q;
			q=first.top();
			if(q.s>q.t){
				second.push(q);
				s-=q.f;
				s+=q.s;
			}
			else{
				third.push(q);
				s-=q.f;
				s+=q.t;
			}
			first.pop();
			}
			
		}
		else if(first.size()<=half&&second.size()>half&&third.size()<=half){//second大于 
		while(second.size()>half){
			stu q;
			q=second.top();
			if(q.f>q.t){
				first.push(q);
				s-=q.s;
				s+=q.f;
			}else{
				third.push(q);
				s-=q.s;
				s+=q.t;
			}
			second.pop();
		}
		}
		else if(first.size()<=half&&second.size()<=half&&third.size()>half){//third大于 
			while(third.size()>half){
			stu q;
			q=third.top();
			if(q.f>q.s){
				first.push(q);
				s-=q.t;
				s+=q.f;
			}else{
				third.push(q);
				s-=q.t;
				s+=q.s;
			}
			third.pop();
			}
		}
		else if(first.size()>half&&second.size()>half&&third.size()<=half){//first与second大 
			while(first.size()>half){
			stu q;
			q=first.top();
			s-=q.f;
			s+=q.t; 
			third.push(q);
			first.pop();
			}
			while(second.size()>half){
			stu q;
			q=second.top();
			s-=q.s;
			s+=q.t; 
			third.push(q);
			second.pop();
			}
		}
		else if(first.size()>half&&second.size()<=half&&third.size()>half){//first与third大 
			while(first.size()>half){
			stu q;
			q=first.top();
			s-=q.f;
			s+=q.s; 
			second.push(q);
			first.pop();
			}
			while(third.size()>half){
			stu q;
			q=third.top();
			s-=q.t;
			s+=q.s; 
			second.push(q);
			third.pop();
			}
		}
		else if(first.size()>half&&second.size()>half&&third.size()<=half){//second与third大 
			while(second.size()>half){
			stu q;
			q=second.top();
			s-=q.s;
			s+=q.f; 
			first.push(q);
			second.pop();
			}
			while(third.size()>half){
			stu q;
			q=third.top();
			s-=q.t;
			s+=q.f; 
			first.push(q);
			third.pop();
			}
		}
		cout<<s<<endl;
	} 

	return 0;
}
