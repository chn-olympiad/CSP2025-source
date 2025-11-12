#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int n,q,cnt=0;
struct squad{
	string member1;
	string member2;
	int len;
}s[N],t;
bool check(string x_1,string x_2,string y_1,string y_2,string z_1,string z_2,string ans_1,string ans_2){
	int len_x=x_1.size();
	int len_y_ans=y_1.size();
	int len_z=z_1.size();
	for(int i=0;i<len_x;i++)
		if(x_1[i]!=x_2[i]) return false;
	for(int i=0;i<len_z;i++)
		if(z_1[i]!=z_2[i]) return false;
	for(int i=0;i<len_y_ans;i++)
		if(y_1[i]!=ans_1[i]||y_2[i]!=ans_2[i]) return false;
	return true;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i].member1;
		cin>>s[i].member2;
		s[i].len=s[i].member1.size();
	}
	while(q--){
		cin>>t.member1;
		cin>>t.member2;
		if(t.member1.size()!=t.member2.size()){
			printf("0\n");
			continue;
		}
		cnt=0;
		t.len=t.member1.size();
		for(int i=0;i<t.len;i++){
			for(int j=1;j<=n;j++){
				if(s[j].len>t.len-i) continue;
				string x_1=t.member1.substr(0,i);
				string x_2=t.member2.substr(0,i);
				string y_1=t.member1.substr(i,s[j].len);
				string y_2=t.member2.substr(i,s[j].len);
				string z_1=t.member1.substr(i+s[j].len,t.len-i-s[j].len);
				string z_2=t.member2.substr(i+s[j].len,t.len-i-s[j].len);
				cnt+=check(x_1,x_2,y_1,y_2,z_1,z_2,s[j].member1,s[j].member2);
			}
		}
		printf("%lld\n",cnt);
	}
    return 0;
}
