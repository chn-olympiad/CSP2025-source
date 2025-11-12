#include<iostream>
#include<queue>
#include<algorithm>
#define int long long
using namespace std;
struct abc{
	int a,b,c,A,B,C;
	operator < (const abc &o)const{
		return a-b>o.a-o.b;
	}
}bu[100005];
bool cmp(abc a,abc b){
	return a.a>b.a;
} 
priority_queue<abc> que1,que2,que3,clean;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		que1=que2=que3=clean;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			if(x==max(x,max(y,z))){
				bu[i].a=x;
				bu[i].A=1;
				if(y==max(y,z)){
					bu[i].b=y;
					bu[i].B=2;
					bu[i].c=z;
					bu[i].C=3;
				}
				else{
					bu[i].b=z;
					bu[i].B=3;
					bu[i].c=y;
					bu[i].C=2;
				}
			}
			else if(y==max(x,max(y,z))){
				bu[i].a=y;
				bu[i].A=2;
				if(x==max(x,z)){
					bu[i].b=x;
					bu[i].B=1;
					bu[i].c=z;
					bu[i].C=3;
				}
				else{
					bu[i].b=z;
					bu[i].B=3;
					bu[i].c=x;
					bu[i].C=1;
				}
			}
			else{
				bu[i].a=z;
				bu[i].A=3;
				if(x==max(x,y)){
					bu[i].b=x;
					bu[i].B=1;
					bu[i].c=y;
					bu[i].C=2;
				}
				else{
					bu[i].b=y;
					bu[i].B=2;
					bu[i].c=x;
					bu[i].C=1;
				}
			}
		}
		sort(bu+1,bu+n+1,cmp);
		int sum1=0,sum2=0,sum3=0,ans=0;
		for(int i=1;i<=n;i++){
			if(bu[i].A==1){
				if(sum1<n/2){
					que1.push(bu[i]);
					sum1++;
					ans+=bu[i].a;
				}
				else{
					if(que1.top().a-que1.top().b<bu[i].a-bu[i].b){
						ans-=que1.top().a;
						ans+=bu[i].a;
						abc change1=que1.top();
						que1.pop();
						que1.push(bu[i]);
						if(change1.B==2){
							ans+=change1.b;
							que2.push(change1);
						}
						else{
							ans+=change1.b;
							que3.push(change1);
						}
					}
					else{
						if(bu[i].B==2){
							ans+=bu[i].b;
							que2.push(bu[i]);
						}
						else{
							ans+=bu[i].b;
							que3.push(bu[i]);
						}
					}
				}
			}
			else if(bu[i].A==2){
				if(sum2<n/2){
					que2.push(bu[i]);
					sum2++;
					ans+=bu[i].a;
				}
				else{
					if(que2.top().a-que2.top().b<bu[i].a-bu[i].b){
						ans-=que2.top().a;
						ans+=bu[i].a;
						abc change1=que2.top();
						que2.pop();
						que2.push(bu[i]);
						if(change1.B==1){
							ans+=change1.b;
							que1.push(change1);
						}
						else{
							ans+=change1.b;
							que3.push(change1);
						}
					}
					else{
						if(bu[i].B==1){
							ans+=bu[i].b;
							que1.push(bu[i]);
						}
						else{
							ans+=bu[i].b;
							que3.push(bu[i]);
						}
					}
				}
			}
			else{
				if(sum3<n/2){
					que3.push(bu[i]);
					sum3++;
					ans+=bu[i].a;
				}
				else{
					if(que3.top().a-que3.top().b<bu[i].a-bu[i].b){
					//	cout<<1;
						ans-=que3.top().a;
						ans+=bu[i].a;
						abc change1=que3.top();
						que3.pop();
						que3.push(bu[i]);
						if(change1.B==1){
							ans+=change1.b;
							que1.push(change1);
						}
						else{
							ans+=change1.b;
							que2.push(change1);
						}
					}
					else{
						if(bu[i].B==1){
							ans+=bu[i].b;
							que1.push(bu[i]);
						}
						else{
							ans+=bu[i].b;
							que2.push(bu[i]);
						}
					}
				}
			}
		//	cout<<ans<<" "<<bu[i].a-bu[i].b<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
