#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","w",stdin); 
    freopen("club.out","s",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b;
		m=b;
		for(int j=1;j<=b;j++){
			cin>>g.a>>g.b>>g.c;
			c.push_back(g);
		}
		f=0;
		sort(c.begin(),c.end(),cnp);
		for(int j=0;j<b;j++){
			if(c.back().b==max(c.back().a,max(c.back().b,c.back().c))&&f<m/2){
				e+=c.back().b;
				f++;
			}else{
				c.back().b=0;
				n.push_back(c.back());
			}
			c.pop_back();
		}
		b-=f; 
		for(int j=1;j<=b;j++){
			c.push_back(n.back());
			n.pop_back();
		}
		f=0;
		sort(c.begin(),c.end(),cmp);
		for(int j=0;j<b;j++){
			if(c.back().a==max(c.back().a,max(c.back().b,c.back().c))&&f<m/2){
				e+=c.back().a; 
				f++;
			}else{
				c.back().a=0;
				n.push_back(c.back());
			}
			c.pop_back();
		}
		b-=f;
		for(int j=1;j<=b;j++){
			c.push_back(n.back());
			n.pop_back();
		}
		f=0;
		sort(c.begin(),c.end(),cnm);
		for(int j=0;j<b;j++){
			if(c.back().c==max(c.back().a,max(c.back().b,c.back().c))&&f<m/2){
				e+=c.back().c; 
				f++;
			}else{
				c.back().b=0;
				n.push_back(c.back());
			}
			c.pop_back();
		}
		b-=f;
		f=0;
		cout<<e<<"\n";
		e=0;
	}
	
	return 0;
}

