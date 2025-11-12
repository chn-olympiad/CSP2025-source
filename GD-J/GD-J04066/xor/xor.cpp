#include<bits/stdc++.h>
#define pii pair<int,int> 
#define f first
#define s second
using namespace std;
int n,k;
int a[500007];
vector<pii>v;
bool cmp(pii a,pii b){
	return a.s<b.s;
}
int cnt;
int last;
int l=1,r=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k<=1){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1) cnt++;
			}
			cout<<cnt;
			return 0;
		}
		else if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0||a[i]==1&&a[i+1]==1&&i<n) cnt++;
			}
			cout<<cnt;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		int num=0;
		for(int j=i;j<=n;j++){
			num^=a[j];
			if(num==k) v.push_back({i,j});
		}
	}
	int num=0;
	sort(v.begin(),v.end(),cmp);
	last=v.front().s;
	cnt=1;
	for(pii num:v){
		if(num.f>last){
			cnt++;
			last=num.s;
		}
	}
	cout<<cnt;
	return 0;
}
