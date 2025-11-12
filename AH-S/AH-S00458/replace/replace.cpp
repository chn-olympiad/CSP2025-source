#include<bits/stdc++.h>
#define for1(i,a,b) for(int i = (a);(i) <= (b);++(i))
#define for2(i,a,b) for(int i = (a);(i) >= (b);--(i))
#define pb push_back
#define pf push_front
using namespace std;
template<typename T> T cmax(T &x,T y){if(x < y) x = y;}
template<typename T> T cmin(T &x,T y){if(x > y) x = y;}
typedef long long LL;
typedef unsigned long long ULL;
const int N = 2e5 + 5;
const int M = 2e5 + 5;
const int MOD = 10007;
int n,q;
string a[N][2];
void solve(){
	cin>>n>>q;
	string s1,s2;
	for1(i,1,n){
		cin>>a[i][0]>>a[i][1];
	}
	for1(i,1,q){
		cin>>s1>>s2;
		if((int)s1.size()!=(int)s2.size()){
			cout<<"0\n";
			continue;
		}
		int len=(int)s1.size();
		s1=" "+s1,s2=" "+s2;
		int ans=0;
		for1(i,1,n){
			string t1="",t2="";
			for1(j,1,len){
                //cout<<s1.substr(j,(int)a[i][0].size())<<" "<<s2.substr(j,(int)a[i][1].size())<<"-"<<t1<<" "<<t1<<"\n";
				if(s1.substr(j,(int)a[i][0].size())==a[i][0]&&
				   s2.substr(j,(int)a[i][1].size())==a[i][1]&&t1==t2&&
				   s1.substr(j+a[i][0].size(),len-j-a[i][0].size()+1)==
				   s2.substr(j+a[i][0].size(),len-j-a[i][0].size()+1)){
                    //cout<<j<<" "<<s1.substr(j,(int)a[i][0].size())<<" "<<s2.substr(j,(int)a[i][1].size())<<" "<<s1.substr(j+a[i][0].size(),len-j-a[i][0].size()+1)<<" "<<s2.substr(j+a[i][0].size(),len-j-a[i][0].size()+1)<<"\n";
				   	ans++;
                }
				t1+=s1[j];
				t2+=s2[j];
			}
		}
		cout<<ans<<"\n";
	}
	return ;
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
int testcase=1;
//cin>>testcase;
while(testcase--){
	solve();
}
    return 0;
}
