#include<bits/stdc++.h>
using namespace std;

#define file
#define infile "club.in"
#define outfile "club.out"

#ifdef file
#define cin ___cin___
#define cout ___cout___
ifstream ___cin___(infile);
ofstream ___cout___(outfile);
#endif

struct node{
	int index,a,b,c,sa,sb,sc,s,ss;
};

int t,n;
long long ans = 0;

vector<node>num,a,b,c;

inline bool cmp(node a,node b){
	return a.ss>b.ss;
}

inline void init(node& s){
	if(s.a>=s.b&&s.a>=s.c){
		s.s = 1;
		s.sa = 0;
		s.sb = s.a-s.b;
		s.sc = s.a-s.c;
	}else if(s.b>=s.a&&s.b>=s.c){
		s.s = 2;
		s.sa = s.b-s.a;
		s.sb = 0;
		s.sc = s.b-s.c;
	}else{
		s.s = 3;
		s.sa = s.c-s.a;
		s.sb = s.c-s.b;
		s.sc = 0;
	}
	s.ss = max(max(s.sa,s.sb),s.sc);
}

inline void algo(){
	cin>>n;
	num.clear();
	a.clear();
	b.clear();
	c.clear();
	ans = 0;
	num.resize(n);
	for(int i = 0;i < n;i++){
		cin>>num[i].a>>num[i].b>>num[i].c;
		num[i].index = i;
		init(num[i]);
		switch(num[i].s){
			case 1:
				a.push_back(num[i]);
				break;
			case 2:
				b.push_back(num[i]);
				break;
			case 3:
				c.push_back(num[i]);
				break;
		}
	}
	sort(a.begin(),a.end(),cmp);
	sort(b.begin(),b.end(),cmp);
	sort(c.begin(),c.end(),cmp);
	
	/*
	cout<<'a';
	for(auto i:a){
		cout<<i.index<<' ';
	}
	cout<<endl<<'b';
	for(auto i:b){
		cout<<i.index<<' ';
	}
	cout<<endl<<'c';
	for(auto i:c){
		cout<<i.index<<' ';
	}
	cout<<endl<<endl;
	*/
	
	if(a.size()>(n/2)){
		for(int i = a.size()-1;i>=n/2;i--){
			int j = a[i].index;
			a.pop_back();
			if(num[j].b>num[j].c){
				b.push_back(num[j]);
			}else{
				c.push_back(num[j]);
			}
		}
	}
	if(b.size()>(n/2)){
		for(int i = b.size()-1;i>=n/2;i--){
			int j = b[i].index;
			b.pop_back();
			if(num[j].a>num[j].c){
				a.push_back(num[j]);
			}else{
				c.push_back(num[j]);
			}
		}
	}
	if(c.size()>(n/2)){
		for(int i = c.size()-1;i>=n/2;i--){
			int j = c[i].index;
			c.pop_back();
			if(num[j].a>num[j].b){
				a.push_back(num[j]);
			}else{
				b.push_back(num[j]);
			}
		}
	}
	
	/*
	cout<<"--------------------------------------\n";
	cout<<'a';
	for(auto i:a){
		cout<<i.index<<' ';
	}
	cout<<endl<<'b';
	for(auto i:b){
		cout<<i.index<<' ';
	}
	cout<<endl<<'c';
	for(auto i:c){
		cout<<i.index<<' ';
	}
	cout<<endl<<endl;
	*/
	
	for(int i = 0;i < a.size();i++){
		ans+=a[i].a;
	}
	for(int i = 0;i < b.size();i++){
		ans+=b[i].b;
	}
	for(int i = 0;i < c.size();i++){
		ans+=c[i].c;
	}
	cout<<ans<<'\n';
}

int main(){
	cin>>t;
	while(t--){
		algo();
	}
	return 0;
}
//3 4 4 2 1 3 2 4 5 3 4 3 5 1 4 0 1 0 0 1 0 0 2 0 0 2 0 2 10 9 8 4 0 0

