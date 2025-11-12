#include<bits/stdc++.h>
#define PII pair<int,int>
#define PIII pair<PII,int>
#define LL long long 
using namespace std;
const int N=1e5+10;
int T,n,cnt[5],seq[N];
struct Node{
	PII s[5];
}a[N];
bool cmp(Node &t1,Node &t2){
	return t1.s[1].first-t1.s[2].first>t2.s[1].first-t2.s[2].first;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	for(cin>>T;T--;){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i].s[j].first;
				a[i].s[j].second=j;
			}
			sort(a[i].s+1,a[i].s+4,greater<PII>());
		}
		memset(cnt,0,sizeof(cnt));
		sort(a+1,a+n+1,cmp);
		LL res=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(cnt[a[i].s[j].second]+1<=n/2){
					cnt[a[i].s[j].second]++;
					res+=a[i].s[j].first;
					break;
				}
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}