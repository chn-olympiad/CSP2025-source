#include<bits/stdc++.h>
using namespace std;
struct stua{
	int a,b,c;
	bool operator<(stua y)const{
		return a-max(b,c)>y.a-max(y.b,y.c);
	}
};
struct stub{
	int a,b,c;
	bool operator<(stub y)const{
		return b-max(a,c)>y.b-max(y.a,y.c);
	}
};
struct stuc{
	int a,b,c;
	bool operator<(stuc y)const{
		return c-max(a,b)>y.c-max(y.a,y.b);
	}
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		priority_queue<stua>a;
		priority_queue<stub>b;
		priority_queue<stuc>c;
		int n;
		cin>>n;
		int res=0;
		for(int i=0;i<n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			if(max({x,y,z})==x){
				if(a.size()<n/2){
					a.push({x,y,z});
					res+=x;
				}else{
					stua mn=a.top();
					int tmp=max(y,z);
					int tmpmn=max(mn.b,mn.c);
					if(mn.a+tmp<x+tmpmn){
						a.pop();
						res-=mn.a;
						a.push({x,y,z});
						res+=x;
						if(tmpmn==mn.b){
							b.push({mn.a,mn.b,mn.c});
							res+=mn.b;
						}else{
							c.push({mn.a,mn.b,mn.c});
							res+=mn.c;
						}
					}else{
						if(tmp==y){
							b.push({x,y,z});
							res+=y;
						}else{
							c.push({x,y,z});
							res+=z;
						}
					}
				}
			}else if(max({x,y,z})==y){
				if(b.size()<n/2){
					b.push({x,y,z});
					res+=y;
				}else{
					stub mn=b.top();
					int tmp=max(x,z);
					int tmpmn=max(mn.a,mn.c);
					if(mn.b+tmp<y+tmpmn){
						b.pop();
						res-=mn.b;
						b.push({x,y,z});
						res+=y;
						if(tmpmn==mn.a){
							a.push({mn.a,mn.b,mn.c});
							res+=mn.a;
						}else{
							c.push({mn.a,mn.b,mn.c});
							res+=mn.c;
						}
					}else{
						if(tmp==x){
							a.push({x,y,z});
							res+=x;
						}else{
							c.push({x,y,z});
							res+=z;
						}
					}
				}
			}else{
				if(c.size()<n/2){
					c.push({x,y,z});
					res+=z;
				}else{
					stuc mn=c.top();
					int tmp=max(x,y);
					int tmpmn=max(mn.a,mn.b);
					if(mn.c+tmp<z+tmpmn){
						c.pop();
						res-=mn.c;
						c.push({x,y,z});
						res+=z;
						if(tmpmn==mn.a){
							a.push({mn.a,mn.b,mn.c});
							res+=mn.a;
						}else{
							b.push({mn.a,mn.b,mn.c});
							res+=mn.b;
						}
					}else{
						if(tmp==x){
							a.push({x,y,z});
							res+=x;
						}else{
							b.push({x,y,z});
							res+=y;
						}
					}
				}
			}
		}
		cout<<res<<endl;
	}
	return 0;
} 
