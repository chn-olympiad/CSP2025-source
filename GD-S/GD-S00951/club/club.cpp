#include<bits/stdc++.h>
#define f(i,a,b) for(int i=a;i<=b;i++)
#define pii pair<int,pair<pair<int,int>,int> >
using namespace std;
priority_queue<int,vector<int>,greater<int> >q1,q2,q3;
int n,a,b,c,sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int _;
	cin>>_;
	while(_--){
	sum=0;
	while(q1.size())q1.pop();while(q2.size())q2.pop();while(q3.size())q3.pop();
	cin>>n;
	f(i,1,n){
		cin>>a>>b>>c;
		if(a>=b&&a>=c){
			sum+=a;
			if(b>=c){
				q1.push(a-b);
			}else{
				q1.push(a-c);
			}
		}else if(b>=a&&b>=c){
			sum+=b;
			if(a>=c){
				q2.push(b-a);
			}else{
				q2.push(b-c);
			}
		}else{
			sum+=c;
			if(a>=b){
				q3.push(c-a);
			}else{
				q3.push(c-b);
			}
		}
	}while(q1.size()>n/2){
		sum-=q1.top();
		q1.pop();
	}while(q2.size()>n/2){
		sum-=q2.top();
		q2.pop();
	}while(q3.size()>n/2){
		sum-=q3.top();
		q3.pop();
	}
	cout<<sum<<"\n";
		
	}
}
