#include<bits/stdc++.h>
using namespace std;
long long s[5005];
long long cnt1;
const long long mod=998244353;
long long tot;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]==1) cnt1++;
	}
	
	if(cnt1==n){
		n-=2;
		for(long long i=1;i<=n;i++){
			tot+=i*(n+1-i);
			tot%=mod;
		}
		cout<<tot;
		return 0;
	}
	
	queue<vector<long long>>q;//0:add 1:mx 2:last 3:cur 4:num
	for(long long i=1;i<=n;i++){
		long long add=s[i],mx=s[i],last=i,cur=i,num=1;
		q.push({add,mx,last,cur,num});
	} 
	while(!q.empty()){
		long long add=q.front()[0],mx=q.front()[1],last=q.front()[2],cur=q.front()[3],num=q.front()[4];
		q.pop();
//						cout<<add<<" "<<mx<<" "<<last<<" "<<cur<<" "<<num;
		if(add>2*mx&&last==cur&&num>=3){
			tot++;
			tot%=mod;
//						cout<<" correct";
		}
//						cout<<endl;
		cur++;
		if(cur>=n+1) continue;
		q.push({add,mx,last,cur,num});
		add+=s[cur];
		mx=max(mx,s[cur]);
		last=cur;
		num++;
		q.push({add,mx,last,cur,num});
	}
	cout<<tot;
	return 0;
}