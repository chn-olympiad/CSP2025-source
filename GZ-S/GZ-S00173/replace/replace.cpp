//GZ-S000173 中央民族大学附属中学贵阳学校 张诗苑
#include<bits/stdc++.h>
using namespace std;
int n,q;
pair<string,string> a[200020],b[200020];
string s1,s2;
int d[][2500020];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
		string x=a[i].first,y=a[i].second;
		int len=x.size();
		for(int i=0;i<)
	}
	for(int i=0;i<q;i++){
		cin>>s1>>s2;
		int cnt1=0,cnt2=0;
		int len=s1.size()
		for(int j=0;j<len;i++){
			cnt1+=((s1[i]-'A')*d[i])%m;
			cnt2+=((s2[i]-'A')*d[i])%m;
		}
		b[i]={cnt1,cnt2};
	}
	for(int i=0;i<n;i++){
		for(int i=0;i<n;i++)
	}
	return 0;
} 
