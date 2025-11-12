#include<bits/stdc++.h>
using namespace std;
#define int long long
int const N=1e5+10;
struct jgt{
	int a,b,c,aq,bq,cq,fi,se,th;
}e[N],et[N];
bool cmpf(jgt a,jgt b){
	return a.aq<b.aq;
}
bool cmps(jgt a,jgt b){
	return a.bq<b.bq;
}
bool cmpt(jgt a,jgt b){
	return a.cq<b.cq;
}
int n;
priority_queue<pair<int,int> > q;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int ti;
	cin>>ti;
	while(ti--){
		int ans=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>e[i].a>>e[i].b>>e[i].c;
		}
		for(int i=1;i<=n;i++){
			e[i].aq=min(e[i].a-e[i].b,e[i].a-e[i].c);
			e[i].cq=min(e[i].c-e[i].a,e[i].c-e[i].b);
			e[i].bq=min(e[i].b-e[i].a,e[i].b-e[i].c);
			int aq=e[i].aq,bq=e[i].bq,cq=e[i].cq;
			int fi=0,se=0,th=0;
			if(aq>bq&&bq>cq) fi=aq,se=bq,th=cq;
			if(aq>cq&&cq>bq) fi=aq,se=cq,th=bq;
			if(bq>aq&&aq>cq) fi=bq,se=aq,th=cq;
			if(bq>cq&&cq>aq) fi=bq,se=cq,th=aq;
			if(cq>bq&&bq>aq) fi=cq,se=bq,th=aq;
			if(cq>aq&&aq>bq) fi=cq,se=aq,th=bq;
			e[i].fi=fi,e[i].se=se,e[i].th=th;
			q.push({fi,i});
		}
		int ans1=0,ans2=0,ans3=0;
		while(q.size()){
			pair<int,int> king=q.top();q.pop();
			int qz=king.first,i=king.second;
			if(qz==e[i].aq){
				if(ans1==n/2){
					if(qz==e[i].fi) q.push({e[i].se,i});
					if(qz==e[i].se) q.push({e[i].th,i});
				}
				else ans+=e[i].a,ans1++;
			}
			if(qz==e[i].bq){
				if(ans2==n/2){
					 if(qz==e[i].fi) q.push({e[i].se,i});
					 if(qz==e[i].se) q.push({e[i].th,i});
				}
				else ans+=e[i].b,ans2++;
			}
			if(qz==e[i].cq){
				if(ans3==n/2){
					if(qz==e[i].fi) q.push({e[i].se,i});
					if(qz==e[i].se) q.push({e[i].th,i});
				}
				else ans+=e[i].c,ans3++;
			}
		}
		cout<<ans<<endl;
		//由于正数是绝对赚的，所以先找正数 
		//找出每个对的权顺序，然后杂算？--用堆 
//		sort(e+1,e+n+1,cmpf);
//		cout<<"a正:"<<" ";
//		for(int i=n;i>=1;i--){
//			if(ans1==n/2) break;
//			if(e[i].aq<0) break;
//			int aq=e[i].aq,bq=e[i].bq,cq=e[i].cq;
//			if(aq<bq||aq<cq) continue;
//			ans1++;
//			ans+=e[i].a;
//			e[i].f=1;
//			cout<<e[i].a<<" ";
//		}
//		cout<<endl;
//		sort(e+1,e+n+1,cmps);
//		cout<<"b正:"<<" ";
//		for(int i=n;i>=1;i--){
//			if(ans2==n/2) break;
//			if(e[i].f) continue;
//			if(e[i].bq<0) break;
//			int aq=e[i].aq,bq=e[i].bq,cq=e[i].cq;
//			if(bq<aq||bq<cq) continue;
//			ans2++;
//			ans+=e[i].b;
//			e[i].f=1;
//			cout<<e[i].b<<" ";
//		}
//		cout<<endl;
//		sort(e+1,e+n+1,cmpt);
//		cout<<"c正:"<<" ";
//		for(int i=n;i>=1;i--){
//			if(ans3==n/2) break;
//			if(e[i].f) continue;
//			if(e[i].cq<0) break;
//			int aq=e[i].aq,bq=e[i].bq,cq=e[i].cq;
//			if(cq<bq||cq<aq) continue;
//			ans3++;
//			ans+=e[i].c;
//			e[i].f=1;
//			cout<<e[i].c<<" ";
//		}
//		cout<<endl;
//		//此时必赚的已经选好，此时重新排一遍不赚的 
//		int top=0;
//		for(int i=1;i<=n;i++){
//			if(e[i].f) continue;
//			et[++top]=e[i];
//		}
//		//用新结构体 
//		sort(e+1,e+n+1,cmpf);
//		for(int i=top;i>=1;i--){
//			int aq=e[i].aq,bq=e[i].bq,cq=e[i].cq; 
//			if(bq>cq){
//				if(ans1==n/2){
//					if(ans2==n/2) ans+=et[i].c,ans3++;
//					else ans+=et[i].b,ans2++;
//				}
//				else ans+=et[i].a,ans1++;
//			}
//			if(cq>bq){
//				if(ans1==n/2){
//					if(ans3==n/2) ans+=et[i].b,ans2++;
//					else ans+=et[i].c,ans3++;
//				}
//				else ans+=et[i].a,ans1++;
//			}
//		}
//		sort(e+1,e+n+1,cmps);
//		for(int i=n;i>=1;i--){
//			int aq=e[i].aq,bq=e[i].bq,cq=e[i].cq; 
//			if(aq>cq){
//				if(ans2==n/2){
//					if(ans1==n/2) ans+=et[i].c,ans3++;
//					else ans+=et[i].a,ans1++;
//				}
//				else ans+=et[i].b,ans2++;
//			}
//			if(cq>aq){
//				if(ans2==n/2){
//					if(ans3==n/2) ans+=et[i].a,ans1++;
//					else ans+=et[i].c,ans3++;
//				}
//				else ans+=et[i].b,ans2++;
//			}
//		}
//		sort(e+1,e+n+1,cmpt);
//		for(int i=n;i>=1;i--){
//			int aq=e[i].aq,bq=e[i].bq,cq=e[i].cq; 
//			if(bq>aq){
//				if(ans3==n/2){
//					if(ans2==n/2) ans+=et[i].a,ans1++;
//					else ans+=et[i].b,ans2++;
//				}
//				else ans+=et[i].c,ans3++;
//			}
//			if(aq>bq){
//				if(ans3==n/2){
//					if(ans1==n/2) ans+=et[i].b,ans2++;
//					else ans+=et[i].a,ans1++;
//				}
//				else ans+=et[i].c,ans3++;
//			}
//		}
//		cout<<ans<<endl;
	}
	
	return 0;
} 
