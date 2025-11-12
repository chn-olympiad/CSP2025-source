#include<bits/stdc++.h>
using namespace std;
int n,q,mal;
string s[200010][2];
map<pair<string,string>,int>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	if(n<=10000){
		for(int i=1;i<=n;i++)
			cin>>s[i][0]>>s[i][1];
		while(q--){
			string st1,st2,t="";
			cin>>st1>>st2;
			t=st1;
			int sum=0;
			for(int i=1;i<=n;i++){
				st1=t;
				int x=st1.find(s[i][0]);
				if(x!=-1){
					st1.erase(x,s[i][0].size());
					st1.insert(x,s[i][1]);
//					cout<<i<<' '<<st1<<'\n';
					if(st1==st2)sum++;
				}
			}
			printf("%d\n",sum);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		string st1,st2;
		cin>>st1>>st2;
		string in1="",in2="";
		int len=st1.size(),pre=0,suf=0;
		for(int j=0;j<len;j++)
			if(st1[j]!=st2[j]){
				pre=j;
				break;
			}
		for(int j=len-1;j>=0;j--)
			if(st1[j]!=st2[j]){
				suf=j;
				break;
			}
		for(int j=pre;j<=suf;j++)
			in1=in1+st1[j],in2=in2+st2[j];
		mal=max(mal,(int)in1.size());
		mp[make_pair(in1,in2)]++;
	}
	while(q--){
		string st1,st2;
		string q1="",q2="";
		cin>>st1>>st2;
		int len=st1.size(),pre=0,suf=0;
		for(int j=0;j<len;j++)
			if(st1[j]!=st2[j]){
				pre=j;
				break;
			}
		for(int j=len-1;j>=0;j--)
			if(st1[j]!=st2[j]){
				suf=j;
				break;
			}
		for(int j=pre;j<=suf;j++)
			q1=q1+st1[j],q2=q2+st2[j];
//		printf("%d %d\n",q1.size(),mal);
//		if(q1.size()>mal)printf("0\n");
		printf("%d\n",mp[make_pair(q1,q2)]);
	}
	return 0;
}
