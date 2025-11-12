#include<bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define of(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=1000;
//const int M=
int n,q;
struct qwq{
	string s1,s2;
}st[N];
string t[N];
string tp[N];
int main(){
	ios::sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	fo(i,1,n){
		cin>>st[i].s1>>st[i].s2;
	}
	int ans=0;
	if(n>=1000||q>=1000){
		fo(i,1,q){
			cout<<0<<endl;
		}
		return 0;
	}
	while(q--){
		string t1,t2;cin>>t1>>t2;
		ans=0;
		int len=t1.size();
		t[0].clear();
		tp[len].clear();
		fo(i,0,len-1){
			if(i==0)t[i]=t[i]+t1[i];
			else t[i]=t[i-1]+t1[i];
		}
		of(i,len-1,0){
			tp[i]=t1[i]+tp[i+1];
		//	cout<<tp[i]<<endl;
		}
		fo(i,1,n){
			int len1=st[i].s1.size();
			fo(j,0,len-len1){
				int flag=0;
				fo(k,0,len1-1){
					if(st[i].s1[k]!=t1[j+k]){
						flag=1;
						break;
					}
				}
				if(flag==0){
					string ne="";
					if(j!=0)ne+=t[j-1];
					ne+=st[i].s2;
					ne+=tp[j+len1];
					if(ne==t2)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

