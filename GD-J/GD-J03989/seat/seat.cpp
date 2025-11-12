#include<bits/stdc++.h>
using namespace std;
const int K=2e6,N=105,M=105;
int a[N*M],n,m,pp;
string k2;
inline void check(string a,string b){
    string s;
    int len;
	freopen(a.c_str(),"r",stdin);
	getline(cin,k2);
	freopen(b.c_str(),"w",stdout);
	for(int i(1);i<=len;++i){
		char p;
		cin>>p;
		if(p!=k2[i-1]){
			cerr<<"Wrong answer on char "<<i<<"\n";
			return ; 
		}
	}
	cerr<<"Accept\n";
}
inline bool cmp(int a,int b){
	return a>b;
}
inline void Main(){
	cin>>n>>m;
    for(int i(1);i<=n*m;++i){
        cin>>a[i];
    }
    pp=a[1];
    sort(a+1,a+1+n*m,cmp);
//    for(int i(1);i<=n*m;++i){
//    	cout<<a[i]<<" ";
//	}
//	cout<<'\n';
	int x=1,y=1;
    for(int i(1);i<=n*m;++i){
        if(a[i]==pp){
        	cout<<y<<" "<<x<<'\n';
        	return ;
        }
        if(y%2==1){
        	x++;
        	if(x>n){
        		y++;
        		x--;
			}
		}else{
			x--;
			if(x==0){
				x++;
				y++;
			}
		}
    }
}
int debug=0;
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    debug=0;
    if(!debug||true){
    	freopen("seat.in","r",stdin),freopen("seat.out","w",stdout);
    	Main();
    	return 0;
	}else{
		for(int test(1);test<=3;++test){
			string s="seat"+to_string(test)+".in",s2="seat"+to_string(test)+".out";
			freopen(s.c_str(),"r",stdin),freopen(s2.c_str(),"w",stdout);
			Main();
			check(s2,"seat"+to_string(test)+".ans");
		}
	}
    return 0;
}
/*
sample1:
2 2
99 100 97 98

1 2

sample2:
2 2
98 99 100 97

2 2

sample3:
3 3
94 95 96 97 98 99 100 93 92

3 1


*/
