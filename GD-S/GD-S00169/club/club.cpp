#include<bits/stdc++.h>
#include<queue>
using namespace std;
const int N=1e5+10;
int a[N][10];
int isin[N],in;
long long ans;
void dfs(int now,int a1,int a2,int a3,int cnt,int n){
	if(!n) return ;
	if(cnt>=ans) ans=cnt;
	if(a1) dfs(now+1,a1--,a2,a3,cnt+=a[now][1],n--);
	if(a2) dfs(now+1,a1,a2--,a3,cnt+=a[now][2],n--);
	if(a3) dfs(now+1,a1,a2,a3--,cnt+=a[now][3],n--);
	
	return ;
}
void work(){
	int in=0,n;
	int num1=0,num2=0,num3=0;
	ans=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q1;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q2;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q3;
	
	cin>>n;
//	if(n<=20){
//		dfs(1,n/2,n/2,n/2,0,n);
//		cout<<ans<<endl;
//		return ; 
//	}
	for(int i=1;i<=n;i++){
		isin[i]=0;
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		q1.push(make_pair(a[i][1]*-1,i));
		q2.push(make_pair(a[i][2]*-1,i));
		q3.push(make_pair(a[i][3]*-1,i));
	}
	int a1,a2,a3,id;
	while(in<n){
		id=a1=a2=a3=0;
		if(!q1.empty()) a1=q1.top().first*-1;
		if(!q2.empty()) a2=q2.top().first*-1;
		if(!q3.empty()) a3=q3.top().first*-1;
		if(a1>=a2&&a1>=a3&&num1<n/2){
			id=q1.top().second;
			if(isin[id]){
				q1.pop();
				continue; 
			}
			in++;
			ans+=a1;
			isin[id]=1;
			num1++;
			q1.pop();
			continue;
		}
		if(a2>=a1&&a2>=a3&&num2<n/2){
			id=q2.top().second;
			if(isin[id]){
				q2.pop();
				continue;
			}
			in++;
			ans+=a2;
			isin[id]=1;
			num2++;
			q2.pop();
			continue;
		}
		if(a3>=a1&&a3>=a2&&num3<n/2){
			id=q3.top().second;
			if(isin[id]){
				q3.pop();
				continue;
			}
			in++;
			ans+=a3;
			isin[id]=1;
			num3++;
			q3.pop();
			continue;
		}
		if(num1<n/2){
			in++;
			ans+=a1;
			isin[id]=1;
			num1++;
			q1.pop();
			continue;
		}
		if(num2<n/2){
			in++;
			ans+=a2;
			isin[id]=1;
			num2++;
			q2.pop();
			continue;
		}
		if(num3<n/2){
			in++;
			ans+=a3;
			isin[id]=1;
			num3++;
			q3.pop();
			continue;
		}
	}
	cout<<ans<<endl;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++) work();
	return 0;
}
