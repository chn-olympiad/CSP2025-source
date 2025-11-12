#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n,q,sum;
struct node{
	int af;
	string s1,s2;
}s[N];
void solve1(){
	for(int x=1;x<=n;x++){
		int cnt=0,len=s[x].s1.size();
		for(int i=0;i<len;i++){
			if(s[x].s1[i]!='a')
				break;
			cnt++;
		}
		s[x].af=cnt;
	}
}
int solve(string s){
	int cnt=0,len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]!='a')
			break;
		cnt++;
	}
	return cnt;
}
bool cmp(node c,node d){
	return c.af<d.af;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i].s1>>s[i].s2;
	solve1();
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		for(int j=1;j<=n;j++){
			if(s[j].af<=solve(a)&&(s[j].s1.size()-1-s[j].af)<=a.size()-1-solve(a))
				sum++;
		}
	}
	cout<<sum;
	return 0;
}
