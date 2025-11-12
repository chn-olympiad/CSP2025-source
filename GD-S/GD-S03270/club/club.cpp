#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
long long t,n,s,sum;
long long read(){
	char x;
	long long y=0;
	y=0;
	x=getchar();
	while(x>='0'&&x<='9'){
		y*=10;
		y+=x-'0';
		x=getchar();
	}
	return y;
}
struct node{
	long long x,y,z;
	bool operator > (const node& a) const {
		if(2*max(x,max(y,z))-x-y-z+min(x,min(y,z))!=2*max(a.x,max(a.y,a.z))-a.x-a.y-a.z+min(a.x,min(a.y,a.z))){
			return 2*max(x,max(y,z))-x-y-z+min(x,min(y,z))>2*max(a.x,max(a.y,a.z))-a.x-a.y-a.z+min(a.x,min(a.y,a.z));
		}
		else{
			return x+y+z-max(x,max(y,z))-2*min(x,min(y,z))>a.x+a.y+a.z-max(a.x,max(a.y,a.z))-2*min(a.x,min(a.y,a.z));
		}
	}
};
priority_queue<node,vector<node>,greater<node>>pqa;
priority_queue<node,vector<node>,greater<node>>pqb;
priority_queue<node,vector<node>,greater<node>>pqc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long a,b,c;
	t=read();
	while(t--){
		sum=0;
		n=read();
		s=n/2;
		for(int i=1;i<=n;i++){
			a=read();b=read();c=read();
			if(a==max(a,max(b,c))){	
			    pqa.push({a,b,c});
				if(pqa.size()>s){
					node h=pqa.top();
					pqa.pop();
					if(h.y>=h.z)pqb.push(h);
					else pqc.push(h);
				}
			}
			else if(b==max(a,max(b,c))){	
			    pqb.push({a,b,c});
				if(pqb.size()>s){
					node h=pqb.top();
					pqb.pop();
					if(h.x>=h.z)pqa.push(h);
					else pqc.push(h);
				}
			}
			else{	
			    pqc.push({a,b,c});
				if(pqc.size()>s){
					node h=pqc.top();
					pqc.pop();
					if(h.x>=h.y)pqa.push(h);
					else pqb.push(h);
				}
			}
		}
		while(!pqa.empty()){
		    sum+=pqa.top().x;
		    pqa.pop();
		}
		while(!pqb.empty()){
		    sum+=pqb.top().y;
		    pqb.pop();
		}
		while(!pqc.empty()){
		    sum+=pqc.top().z;
		    pqc.pop();
		}
		cout<<sum<<endl;
	}
	return 0;
}
