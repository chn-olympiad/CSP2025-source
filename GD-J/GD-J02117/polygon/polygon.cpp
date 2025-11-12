#include <bits/stdc++.h>
#define int long long
using namespace std;
//const int MOD=998244353;
int ans,n,a[5005];
//struct stu{
//	string s;
//	int ch;
//	int sum;
//	int mx;
//};
//queue<stu>q;
//bool find(stu x){
//	int m=q.size();
//	while(m--){
////		cout<<"finding...\n";
//		if(q.front().s==x.s&&q.front().sum==x.sum&&q.front().ch==x.ch&&q.front().mx==x.mx){
//			return 0;
//		}
//	}
//	return 1;
//}
//void solve(){
//	while(!q.empty()){
//		stu p=q.front();
//		q.pop();
////		cout<<p.s<<" "<<p.ch<<" "<<p.sum<<" "<<p.mx<<"\n";
//		for(int i=p.ch;i<n;i++){
////			cout<<(p.s[i]=='0')<<"   testing...\n";
//			if(p.s[i]=='0'){
////				cout<<"in!\n";
//				stu pp;
//				string s1=p.s;
//				s1[i]='1';
//				int sum1=p.sum+a[i];
//				int mx1=max(p.mx,a[i]);
//				pp={s1,p.ch+1,sum1,mx1};
//				if(p.ch<3){
//					q.push(pp);
//				}
//				if(p.ch>=3&&sum1>2*mx1&&find(pp)){
////					cout<<"success!\n";
//					ans++;
////					cout<<pp.s<<" "<<pp.ch<<" "<<p.sum<<" "<<p.mx<<"\n";
//					q.push(pp);
//				}
//			}
//		}
//	}
//}
void meizhaole(int i,int choose,int sum,int mx){//รปีะมห 
	if(i>=n){
		if(choose>=3&&sum>2*mx)ans++;
		return;
	}
	meizhaole(i+1,choose+1,sum+a[i],max(mx,a[i]));
	meizhaole(i+1,choose,sum,mx);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%lld",&n);
    bool flag=1; 
//    string ss="";
    for(int i=0;i<n;i++){
    	scanf("%lld",a+i);
    	if(a[i]!=1)flag=0;
//    	ss+='0';
	}
//	q.push({ss,0,0,0});
//	solve();
	if(flag){
		cout<<((n-1)*(n-2))/2; 
		return 0;
	}
	meizhaole(0,0,0,0);
	printf("%lld",ans);
	
	return 0;
}

