#include<iostream>
#include<bits/stdc++.h> 
#include<queue>
using namespace std;
int t,n,hn,p[3]={0},p1,p2,p3;
vector<int> anss;
priority_queue<int,vector<int>,less<int> > a,b,c;
void join(int pos,int num){
	hn=n/2;
	if(pos==0){
		if(a.size()<hn){
			a.push(num);
			p1++;
			return;
		}
		else{
			if(num>a.top()){
				a.pop();
				a.push(num);
				return;
			}
			else{
				return;
			}
		}
	}
	if(pos==1){
		if(b.size()<hn){
			b.push(num);
		}
		else{
			if(num>a.top()){
				b.pop();
				b.push(num);
			}
		}
	}
	if(pos==2){
		if(c.size()<hn){
			c.push(num);
		}
		else{
			if(num>c.top()){
				c.pop();
				c.push(num);
			}
		}
	}
}

vector<int> in(){
	vector<int> tmp;
	tmp.reserve(3);
	for(int i=0;i<3;i++){
		int a;
		cin>>a;
		tmp.push_back(a);
	}
	return tmp;
}

int happy(int n){
	int ans=0; 
	hn=n/2;
	vector<vector<int> > h;
	h.reserve(n);
	vector<int> n1,n2,n3;
	for(int i=0;i<n;i++){
		h.push_back(in());
	}
	/*for(int i=0;i<n;i++){
		for(int k=0;k<3;k++){
			for(int i2=0;i2<n;i2++){
				for(int k2=0;k2<3;k2++){
					if(i==i2||k==k2){
						continue;
					}
					ans+=h[i][k];
					p[i]++;
					if(p[i]<hn){
						
					}
				}
			}
		}
	}*/
	/*for(int i=0;i<h.size();i++){
		for(int ht=0;ht<3;ht++){
			cout<<h[i][ht]<<" ";
		}
		cout<<endl;
	}*/
	while(h.size()!=0){
		int m=0,pos=0;
		for(int i=0;i<3;i++){
			if(m<h[0][i]){
				m=h[0][i];
				pos=i;
			}
		}
		join(pos,m);
		h.erase(h.begin());
	}
	/*while(h.size()!=0){
		int m=-1,pos=0;
		for(int i=0;i<3;i++){
			if(m<=h[0][i]){
				m=h[0][i];
				pos=i;
			}
		}
		if(pos==0){
			if(p1<hn){
				join(pos,m);
				h.erase(h.begin());
				cout<<"p1+"<<m<<endl;
				continue;
			}
			else{
				h[0][pos]=0;
				cout<<"p1set0!"<<endl;
				continue;
			}
		}
		if(pos==1){
			if(p2<hn){
				join(pos,m);
				h.erase(h.begin());
				cout<<"p2+"<<m<<endl;
				continue;
			}
			else{
				h[0][pos]=0;
				cout<<"p2set0!"<<endl;
				continue;
			}
		}
		if(pos==2){
				join(pos,m);
				h.erase(h.begin());
				cout<<"p3+"<<m<<endl;
				continue;
			}
			else{
				h[0][pos]=0;
				cout<<"p3set0!"<<endl;
				continue;
			}
		}
	}*/
	while(a.size()!=0){
		ans+=a.top();
		a.pop();
	}
	while(b.size()!=0){
		ans+=b.top();
		b.pop();
	}
	while(c.size()!=0){
		ans+=c.top();
		c.pop();
	}
	return ans;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		anss.push_back(happy(n));
	}
	for(int i=0;i<anss.size();i++){
		cout<<anss[i]<<endl;
	}
	return 0;
}
