#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+5;
long long a[N],b[N];
long long pre[N],dp[N],vis[N];
long long n,m,k,t,sum=0,ans=0,mx,mn;
struct al{
	long long x,y,sum=0;
}c[N];
vector<long long>v;
string s,s1,s2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0); 
	
	cin>>n>>m;
	set<long long>st;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		st.insert(a[i]);
	}
	for(auto x:st){
		sum++;
		if(x==a[1]){
			k=sum;
			break;
		}
	}
	k=n*m-k+1;
//	cout<<k<<endl;
	int x;
	if(k%m!=0)x=k/m+1;
	else x=k/m;
	cout<<x<<" ";
	if(x%2==1){
		cout<<k-(x-1)*m;//<<"*";
//		cout<<k<<" "<<(x-1)*m<<endl;
	}else {
		cout<<m+1-(k-(x-1)*m);//<<"/";
	}
	return 0;
}
/*
2 2
99 100 97 98

1 2
--
2 2
98 99 100 97

2 2
--
3 3
94 95 96 97 98 99 100 93 92

3 1
--
2 3
3 2 1 4 5 6

2 3

*/