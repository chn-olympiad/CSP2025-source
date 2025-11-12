#include<bits/stdc++.h>
using namespace std;
struct club{
	int c1;
	int c2;
	int c3;
}a[100010];
struct minstack1{
	stack<int> q;
	void push(int x){
		stack<int> q1;
		int e=q.size();
		while(e--){
			if(a[q.top()].c1<a[x].c1) {
				q1.push(q.top());
				q.pop();
			}
			else break;
		}
		q.push(x);
		e=q1.size();
		while(e--){
			q.push(q1.top());
			q1.pop();
		}
		return;
	}
	void pop(){
		q.pop();
	}
	int top(){
		return q.top();
	}
	int size(){
		return q.size();
	}
};
struct minstack3{
	stack<int> q;
	void push(int x){
		stack<int> q1;
		int e=q.size();
		while(e--){
			if(a[q.top()].c3<a[x].c3) {
				q1.push(q.top());
				q.pop();
			}
			else break;
		}
		q.push(x);
		e=q1.size();
		while(e--){
			q.push(q1.top());
			q1.pop();
		}
		return;
	}
	void pop(){
		q.pop();
	}
	int top(){
		return q.top();
	}
	int size(){
		return q.size();
	}
};
struct minstack2{
	stack<int> q;
	void push(int x){
		stack<int> q1;
		int e=q.size();
		while(e--){
			if(a[q.top()].c2<a[x].c2) {
				q1.push(q.top());
				q.pop();
			}
			else break;
		}
		q.push(x);
		e=q1.size();
		while(e--){
			q.push(q1.top());
			q1.pop();
		}
		return;
	}
	void pop(){
		q.pop();
	}
	int top(){
		return q.top();
	}
	int size(){
		return q.size();
	}
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,c1v,c2v,c3v;
	cin>>t;
	while(t--){
		cin>>n;
		minstack1 c1p;
		minstack2 c2p;
		minstack3 c3p;
		c1v=c2v=c3v=0;
		for(int i=0;i<n;i++){
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
			if(a[i].c1>=a[i].c2&&a[i].c1>=a[i].c3){
				c1v+=a[i].c1;
				c1p.push(i);
			}
			else if(a[i].c2>=a[i].c1&&a[i].c2>=a[i].c3){
				    c2v+=a[i].c2;
				    c2p.push(i);
			    }
			else{if(a[i].c3>=a[i].c2&&a[i].c3>=a[i].c1){
				    c3v+=a[i].c3;
				    c3p.push(i);}} 
		}
		while(1){
			if(c1p.size()>n/2){
				c1v-=a[c1p.top()].c1;
				if(a[c1p.top()].c2>a[c1p.top()].c3){
					c2v+=a[c1p.top()].c2;
				}
				else{
					c3v+=a[c1p.top()].c3;
				}
			c1p.pop();
			}
			else break;
		}
		while(1){
			if(c2p.size()>n/2){
				c2v-=a[c2p.top()].c2;
				if(a[c2p.top()].c1>a[c2p.top()].c3){
					c1v+=a[c2p.top()].c1;
				}
				else{
					c3v+=a[c2p.top()].c3;
				}
			c2p.pop();
			}
			else break;
		} 
		while(1){
			if(c3p.size()>n/2){
				c3v-=a[c3p.top()].c3;
				if(a[c3p.top()].c1>a[c3p.top()].c2){
					c1v+=a[c3p.top()].c1;
				}
				else{
					c2v+=a[c3p.top()].c2;
				}
			c3p.pop();
			}
			else break;
		}
		cout<<c1v+c2v+c3v<<endl;
	}
	return 0;
}

