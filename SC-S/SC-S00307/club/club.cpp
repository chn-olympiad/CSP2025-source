#include<bits/stdc++.h>
#define int long long 
#define PII pair<int,int>
#define A3 array<int,3>
using namespace std;
const int N = 1e5 + 10,mod = 1e9 + 7,base = 131;
int T,n,m;
struct node{
	int a,b,c;
}p[N];
int tmp[5];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		priority_queue<int,vector<int>,greater<int>> q1,q2,q3;
		int A=0,B=0,C=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			tmp[1]=p[i].a,tmp[2]=p[i].b,tmp[3]=p[i].c;
			sort(tmp+1,tmp+1+3); reverse(tmp+1,tmp+1+3); 
			//for(int j=1;j<=3;j++) cout<<tmp[j]<<" \n"[j==3];
			if(p[i].a==tmp[1]){
				A++;
				q1.push(tmp[1]-tmp[2]); 
			} else if(p[i].b==tmp[1]){
				B++;
				q2.push(tmp[1]-tmp[2]);
			} else {
			    C++;
			    q3.push(tmp[1]-tmp[2]);
			}
			ans+=tmp[1];
		}
		while(A>n/2){
			A--;
			auto x=q1.top(); q1.pop();
			ans-=x;
		}
		while(B>n/2){
			B--;
			auto x=q2.top(); q2.pop();
			ans-=x;
		}
		while(C>n/2){
			C--;
			auto x=q3.top(); q3.pop();
			ans-=x;
		}
		cout<<ans<<"\n"; 
	}
	return 0;
} 
/*
g++ -std=c++14 club.cpp -o work
*/
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/


