#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int res[100002];
struct satisfy{
	int f;
	int s;
	int t;
	int acl;
	int bcl;
	int ccl;
};
satisfy s[100002];
priority_queue<int,vector<int>,greater<int> > a;
priority_queue<int,vector<int>,greater<int> > b;
priority_queue<int,vector<int>,greater<int> > c;

void club(int p){
	if(s[p].f==1){
		if(a.size()+1>(n/2)){
			if(b.size()+1>(n+2)){
				c.push(i);
			}
			else{
				b.push(i);
			}
		}
		else{
			a.push(i);
		}
		
	}
	if(s[p].f==2){
		if(a.size()+1>(n/2)){
			if(b.size()+1>(n+2)){
				c.push(i);
			}
			else{
				b.push(i);
			}
		}
		else{
			a.push(i);
		}
		
	}	
	if(s[p].f==3){
		b.push(i);
	}	
} 

void compare(int i){
	if(s[i].acl>=s[i].bcl){
		if(s[i].acl>=s[i].ccl){
			s[i].f=1;
			if(s[i].bcl>=s[i].ccl){
				s[i].s=2;
				s[i].t=3;
			}
			else{
				s[i].s=3;
				s[i].t=2;
			}
		}
		else{
			s[i].f=3;
			s[i].s=1;
			s[i].t=2;
		}
	}
	else{
		if(s[i].bcl>=s[i].ccl){
			s[i].f=2;
			if(s[i].acl>=s[i].ccl){
				s[i].s=1;
				s[i].t=3;
				
			}
			else{
				s[i].s=1;
				s[i].t=3;
			}
			
		}
		else{
			s[i].f=3;
			s[i].s=2;
			s[i].t=1;
		}
	}
	cout<<s[i].f<<" "<<s[i].s<<" "<<s[i].t<<endl;
}
int main(){
//freopen("club.in","r",stdin);
//freopen("club.out","w",stdout);	
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=1;i<=n;i++){			
			cin>>s[i].acl>>s[i].bcl>>s[i].ccl;
			
		}
		for(int i=1;i<=n;i++){
			compare(i);
		} 
		for(int i=1;i<=t;i++){
			club(i);
		}
		
	}
	return 0;
} 
