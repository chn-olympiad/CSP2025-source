#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
string s1[200005],s2[200005];
string t1,t2;
struct node{
	int qq,hh;
}aa[200005],ab[200005];
int cot1(string k){
	int sum=0;
	for(int i=0;k[i]=='a';++i){
		++sum;
	}
	return sum;
}
int cot2(string k){
	int i;
	for(i=0;k[i]=='a';++i);
	return k.size()-i-1;
}
bool check(string l,string u){
	int len=l.size();
	for(int i=0;i<len;++i){
		if((l[i]!='a'&&l[i]!='b')||(u[i]!='a'&&u[i]!='b'))return 1;
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	int n,q;
	bool bo=1;
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s1[i]>>s2[i];
		if(check(s1[i],s2[i]))bo=0;
	}
	for(int i=1;i<=n;++i){
		aa[i].qq=cot1(s1[i]);
		aa[i].hh=cot2(s1[i]);
		ab[i].qq=cot1(s2[i]);
		ab[i].hh=cot2(s2[i]);
	}
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		if(check(t1,t2))bo=0;
		if(bo){
			int cnt1q=cot1(t1),cnt1h=cot2(t1);
			int cnt2q=cot1(t2),cnt2h=cot2(t2);
			for(int i=1;i<=n;++i){
				if((cnt1q>=aa[i].qq)&&(cnt1h>=aa[i].hh)&&(cnt1q-aa[i].qq+ab[i].qq==cnt2q)&&(cnt1h-aa[i].hh+ab[i].hh==cnt2h))++ans;
			}
			cout<<ans<<endl;
			continue;
		}
		int len=t1.size();
		for(int i=1;i<=n;++i){
			string h1="",h2="";
			int cnt=0,bj=-1,x=s1[i].size();
			for(int j=0;j<len;++j){
				if(cnt==x-1)break;
				if(t1[j]==s1[i][cnt]){
					if(cnt==0)bj=j;
					++cnt;
				}
				else j=bj,bj=-1,cnt=0;
			}
			if(bj==-1)continue;
			else{
				for(int j=0;j<bj;++j)h1+=t1[j];
				for(int j=bj+cnt+1;j<=n;++j)h2+=t1[j];
				string h3=h1+s2[i]+h2;
				if(h3==t2)++ans;
			}
		}
		cout<<ans<<endl;
	}
	return  0;
}
