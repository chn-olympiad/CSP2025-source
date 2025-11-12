#include<iostream>
#include<algorithm>
using namespace std;
int n,q,cnt=0;
string s1[200010],s2[200010],l1,l2,tmp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	for(;q--;){
		cin>>l1>>l2;
		tmp=l1;
		for(int i=1,pos=-1;i<=n;i++){
			while(tmp.find(s1[i],pos+1)!=string::npos){
				pos=tmp.find(s1[i],pos+1);
				tmp.replace(pos,s1[i].size(),s2[i]);
				if(tmp==l2)cnt++;
				tmp=l1;
			}
			pos=-1;
		}
		cout<<cnt<<'\n';
		cnt=0;
	}
	return 0;
}
