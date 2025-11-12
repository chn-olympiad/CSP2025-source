#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,K;
int const D=5e5+50;
int a[D]; 
vector<pair<int,int> >t;
vector<pair<int,int> >s;
long long ans=0;
int num[D];
int cnt;
int hz[D];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>K;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		hz[i]=hz[i-1]^a[i];
	}
	int l=1;
	for(int i=1;i<=n;i++){
		num[cnt]^=a[i];
		if(a[i]==K){
			cnt++;
			t.push_back(make_pair(l,i));
			l=i+1;
		}
		else if(i==n)t.push_back(make_pair(l,i));
	}
	for(int i=0;i<t.size();i++){
		int df=t[i].second-t[i].first;
		if(df==0&&num[i]==K){
			s.push_back(make_pair(t[i].first,t[i].second));
			continue;
		}
		for(int j=0;j<=df;j++){
			for(int k=0;k<=df;k++){
				if(j+k>df)continue;
				int q0=hz[t[i].first+j-1]^hz[t[i].first-1];
				int q1=hz[t[i].second]^hz[t[i].second-k];
				int lxt=num[i]^q0;
				lxt^=q1;
				if(lxt==K){
					s.push_back(make_pair(t[i].first+j,t[i].second-k));
				}
			}
		}
	}
	sort(s.begin(),s.end());
	int r=-5;
	for(int i=0;i<s.size();i++){
		while(i+1<s.size()&&s[i+1].second<s[i].second){
			i++;
		}
		if(s[i].first>r){
			ans++;r=s[i].second;
		}
	}
	cout<<ans;
	return 0;
}
