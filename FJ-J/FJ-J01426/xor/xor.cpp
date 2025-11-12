#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
int a[100005],s[100005];
struct pt{
	int l,r;
	vector<int>s; 
	pt(int l1,int r1,vector<int> s1){
		l=l1,r=r1,s=s1;
	}
};
vector<pt>v;
bool cmp1(pt a,pt b) {
	if(a.l<b.l)return 1;
	else if(a.l>b.l)return 0;
	else {
		if(a.r<b.r)return 1;
		else return 0;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[j]^s[i-1])==k)v.push_back(pt(i,j,vector<int>()));
		}
	} 
	sort(v.begin(),v.end(),cmp1);
	int lv=v.size();
	for(int i=0;i<lv;i++){
		for(int j=i+1;j<lv;j++){
			if(v[i].r>=v[j].l)v[i].s.push_back(j);
			else break;
		}
	} 
	int now=0;
	while(now<v.size()){
		cnt++;
		if(v[now].s.empty())now++;
		else now=v[now].s[v[now].s.size()-1]+1;
	}
	cout<<cnt;
	return 0;
}

