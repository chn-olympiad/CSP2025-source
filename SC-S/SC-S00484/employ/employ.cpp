#include<bits/stdc++.h>
using namespace std;
long long f(int n){
	long long s=1;
	for(int i=1;i<=n;i++){
		s*=i;
	}
	return s;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	string str;
	cin>>str;
	int a[555];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n == m){
		set<int> b;
		for(int i=0;i<str.length();i++){
			if(str[i] == '0'){
				cout<<0;
				return 0;
			}
			else{
				b.insert(a[i+1]);
			}
		}
		bool flag = true;
		for(int i=1;i<n;i++){
			if(a[i] == a[i+1]){
				flag = !flag;
				break;
			}
		}
		if(flag)cout<<f(n)/f(n-m)%998244353;
		else{
			cout<<0;
		}
	} 
	cout<<0; 
	//我好像看见洛谷专栏在等我了........................ 
	/*mengbier;
	luogu~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	HHHHHHHHHHHHHHHHHHHHHHHHHa!
	 Wow————————————————————————————————————————————————————————————————————————————— 
	xixixixixixixixixixixixi~~~~
	CSP真是个好东西====================================================================================C++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	orz orz orz orz 行不行？！
	乱花渐欲迷人眼，浅草才能没马蹄 。晓镜但愁云鬓改，夜吟应觉月光寒 。 姑苏城外寒山寺，夜半钟声到客船。 同是天涯沦落人，相逢何必曾相识。今日听君歌一曲，暂凭杯酒长精神。 正是江南好风景，落花时节又逢君。山回路转不见君，雪上空留马行处。金风玉露一相逢，便胜却人间无数。惶恐滩头说惶恐，零丁洋里叹零丁。落红不是无情物，化作春泥更护花。END! 
	its-me-its-me*/ 
	return 0;
}
		