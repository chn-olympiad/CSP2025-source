#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a);i<=(int)(b);i++)
using ll=long long;
const int Cnt=2e5+4;
int n,q;
struct f{
	string s1,s2;
};
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	vector<f> A(n+4);
	REP(z,1,n)cin>>A[z].s1>>A[z].s2;
	string t1,t2,t3;
	REP(z,1,q){
		cin>>t1>>t2;
		int flag=0;
		REP(i,0,t1.size()-1){
			if(t1[z]!=t2[z]){
				if(flag==2){
					flag=3;
					break;
				}
				flag=1;
				t3+=t1[z];
			}
			else if(flag)flag=2;
		}
		if(flag==3){
			cout<<0<<'\n';
			continue;
		}
		int sum=0;
		REP(i,1,n){
			int a=t1.find(A[i].s1),b=t2.find(A[i].s2),c=A[i].s1.find(t3);
			if(b<(int)t2.size() && a<(int)t1.size() && c<(int)A[i].s1.size() && a>=0 && b>=0 && c>=0)sum++;
		}
		cout<<sum<<'\n';
	}
	return 0;
}