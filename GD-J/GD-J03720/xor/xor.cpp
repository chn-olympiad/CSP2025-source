//我承诺遵守中国计算机学会相关规定
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll a[500020];
ll s[1100][1100];
vector< pair< int, int > > ss;
bool cmp(const pair<int,int>& a1,const pair<int,int>& b1){
	if(a1.second!=b1.second){
		return a1.second<b1.second;
	}
	else{
		return a1.first<b1.first;
	}
}
/*
Is this problem a Dynamic Programming
or 贪心?
I think it's the first.
But how to work out it?
L! I! N! U! X! 2.0!
You are too different from Windows.
In fact, I cannot solve this problem probably.
*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n>1000) return 0;
	if(n==1){
		cin>>a[1];
		if(a[1]==k) cout<<1;
		else cout<<0;
		return 0;
	}
	if(n==2){
		int asn=0;
		cin>>a[1]>>a[2];
		if(a[1]==k) asn++;
		if(a[2]==k) asn++;
		if(a[1]^a[2]==k) asn==2?asn=2:asn=1;
		cout<<asn;
		return 0;
	}
//	for(int i=1; i<=n; ++i){
//		cin>>a[i];
//	}
//	ll ans=0;
//	// ((a^b)^c) = (a^(b^c))
//	for(int i=1; i<=n; ++i){
//		for(int j=i; j<=n; ++j){
//			if(i==j) s[i][j]=a[i];
//			else{
//				s[i][j]=s[i][j-1]^a[j];
//			}
//			if(s[i][j]==k) ss.push_back(make_pair(i,j));
//		}
//	}
//	sort(ss.begin(),ss.end(),cmp);
	return 0;
}












//GD-J03720 R.I.P
//miss him.


/*
9:30 强者在思考 
9:33 My Chinese Shu Ru Fa Is Broken!!!
9:34 啊回来了
9:49 没有思路，下一题 
9:54 算了回来吧，仔细想一想…… 
11:25 …… 
11:30 100+100+5+12=217, 2= :(
*/

// you can search /user/1470495 on Lg :)
//目测<普及->至<普及/提高-> 
