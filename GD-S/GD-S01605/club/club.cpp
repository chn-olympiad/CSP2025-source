#include<bits/stdc++.h>
using namespace std;
int n=0;
int news[100007][2];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int ans[t];
    for(int T=0;T<t;T++){
    	cin>>n;
    	int nans=0;
        priority_queue<int,vector<int>,greater<int> > r1;
        priority_queue<int,vector<int>,greater<int> > r2;
        priority_queue<int,vector<int>,greater<int> > r3;
    	for(int i=0;i<n;i++){
    		int x,y,z;
    		cin>>x>>y>>z;
    		if(x>=y && x>=z){
    			news[i][0]=x;
    			news[i][1]=min(x-y,x-z);
    			r1.push(news[i][1]);
    			nans+=x;
			}
    		if(y>x && y>=z){
    			news[i][0]=y;
    			news[i][1]=min(y-x,y-z);
    			r2.push(news[i][1]);
    			nans+=y;
			}
    		if(z>y && z>x){
    			news[i][0]=z;
    			news[i][1]=min(z-x,z-y);
    			r3.push(news[i][1]);
    			nans+=z;
			}
    	}
		int sz1=r1.size();
		int sz2=r2.size();
		int sz3=r3.size();
		int bgg=n/2;
		while(sz1>bgg){
			nans-=r1.top();
			r1.pop();
			sz1--;
		}
		while(sz2>bgg){
			nans-=r2.top();
			r2.pop();
			sz2--;
		}
		while(sz3>bgg){
			nans-=r3.top();
			r3.pop();
			sz3--;
		}
		ans[T]=nans;
		n=0;
	}
	for(int T=0;T<t;T++){
		cout<<ans[T]<<endl;
	}
	return 0;
} 
