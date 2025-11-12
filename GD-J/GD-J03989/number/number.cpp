#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
string s;
bool debug=0;
int k[N],len,l;
inline bool isdigit(char c){
    if(c>='0'&&c<='9')
        return 1;
    else 
        return 0;
}
inline bool cmp(int a,int b){
    return a>b;
}
inline void Main(){
    cin>>s;
    len=s.size();
    l=0;
    for(int i(0);i<len;++i){
        if(isdigit(s[i])){
            k[++l]=s[i]-'0';
        }
    }
    sort(k+1,k+1+l,cmp);
    for(int i(1);i<=l;++i){
        cout<<k[i];
    }
    cout<<'\n';
}
char k2[N<<1];
inline void check(string c,string a,string b){
	freopen(c.c_str(),"r",stdin);
	cin>>s;
	len=s.size();
	freopen(a.c_str(),"r",stdin);
	for(int i(1);i<=len;++i){
		cin>>k2[i];
	}
	freopen(b.c_str(),"w",stdout);
	for(int i(1);i<=len;++i){
		char p;
		cin>>p;
		if(p!=k2[i]){
			cerr<<"Wrong answer on char "<<i<<"\n";
			return ; 
		}
	}
	cerr<<"Accept\n";
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    debug=0;
    if(!debug||true){
        freopen("number.in","r",stdin),freopen("number.out","w",stdout);
        Main();
        return 0;
    }else{
        for(int test=1;test<=4;++test){
            string s="number"+to_string(test)+".in",s2="number"+to_string(test)+".out";
            freopen(s.c_str(),"r",stdin);
			freopen(s2.c_str(),"w",stdout);
            Main();
//            cerr<<s<<" "<<s2<<'\n';
			check(s,s2,"number"+to_string(test)+".ans");
        }
        
    }
    return 0;
}
