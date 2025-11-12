#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,mod=998244353;
struct e{
	int aq,bq,cq;
}s[N];

int n,a[N][5],ans,cnt1,cnt2,cnt3;
bool flag1,flag2;

bool cmp1(e A,e B){
	return A.aq>B.aq;
}

bool cmp2(e A,e B){
	if(A.aq-A.bq==B.aq-B.bq){
		return A.aq>B.aq;
	}
	return A.aq-A.bq>B.aq-B.bq;
}

void dfs(int k,int sum){
	if(k==n+1){
		ans=max(ans,sum);
	}
	else{
		if(cnt1<n/2) {
			cnt1++;
			dfs(k+1,sum+a[k][1]);
			cnt1--;
		}
		if(cnt2<n/2) {
			cnt2++;
			dfs(k+1,sum+a[k][2]);
			cnt2--;
		}
		if(cnt3<n/2) {
			cnt3++;
			dfs(k+1,sum+a[k][3]);
			cnt3--;
		}
	}
}

void solve(){
	cin>>n;
	ans=cnt1=cnt2=cnt3=0;
	flag1=flag2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]) flag1=0;
		if(a[i][3]) flag2=0;
	}
	if(flag1 && flag2){
		for(int i=1;i<=n;i++){
			s[i].aq=a[i][1];
			s[i].bq=a[i][2];
			s[i].cq=a[i][3];
		}
		sort(s+1,s+1+n,cmp1);
		for(int i=1;i<=n/2;i++){
			ans+=s[i].aq;
		}
		cout<<ans<<"\n";
	}
	else if(!flag1 && flag2){
		for(int i=1;i<=n;i++){
			s[i].aq=a[i][1];
			s[i].bq=a[i][2];
			s[i].cq=a[i][3];
		}
		sort(s+1,s+1+n,cmp2);
		for(int i=1;i<=n/2;i++){
			ans+=s[i].aq;
		}
		for(int i=n/2+1;i<=n;i++){
			ans+=s[i].bq;
		}
		//cout<<111;
		cout<<ans<<"\n";
	}
	else if(n<=10){
		dfs(1,0);
		cout<<ans;
	}
	else {
		for(int i=1;i<=n;i++){
			s[i].aq=a[i][1];
			s[i].bq=a[i][2];
			s[i].cq=a[i][3];
		}
		sort(s+1,s+1+n,cmp2);
		for(int i=1;i<=n;i++){
			cout<<"       "<<i<<"  :  "<<s[i].aq<<"   "<<s[i].bq<<"   "<<s[i].cq<<"\n";
			if(s[i].aq>s[i].bq && s[i].aq>s[i].cq && cnt1<n/2){
				
				//cout<<1<<":  "<<i<<"   "<<s[i].aq<<"\n";
				cnt1++;
				ans+=s[i].aq;
			}
			else if(cnt2<n/2){
				//cout<<2<<":  "<<i<<"   "<<s[i].bq<<"\n";
				cnt2++;
				ans+=s[i].bq;
			}
			else{
				//cout<<3<<":  "<<i<<"   "<<s[i].cq<<"\n";
				cnt3++;
				ans+=s[i].cq;
			}
		}
		cout<<ans<<"\n";
	}
	
}

int main(){
	//freopen("club4.in","r",stdin);
	//freopen("club4.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}
/* 
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
/*
147325
*/

