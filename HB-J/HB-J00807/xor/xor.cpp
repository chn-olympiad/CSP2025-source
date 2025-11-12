#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
#include<cstdio>
using namespace std;
string a[500010],sk;
int f[500010],x[500010],mx = -1e9;
int n,k;
string totwostring(int x){
	if(x == 0) return "0";
	string s = "";
	while(x){
		s = char(x % 2 + '0') + s;
		x = x / 2.0;
	}
	while(s.size() != 20){
		s = '0' + s;
	}
	return s;
}
string xorstring(string s1,string s2){
	if(s1 == "") return s2;
	string s3 = "";
	if(s1.size() < s2.size()) swap(s1,s2);
	for(int j = s1.size() - 1;j >= 0;j--){
		if(s2[j] != '1' && s2[j] != '0') s3 = s1[j] + s3;
		else if(s1[j] != s2[j]) s3 = '1' + s3;
		else s3 = '0' + s3;
	}
	return s3;
}
void dfs(int step,int cnt,string sx){
	if(sx == sk) {
		cnt++;
		sx = "";
	}
	if(step == n){
		mx = max(mx,cnt);
		return;
	}
	dfs(step + 1,cnt,xorstring(sx,a[step + 1]));
	dfs(step + 1,cnt,a[step + 1]);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	sk = totwostring(k);
	for(int i = 1;i <= n;i++){
		cin>>x[i];
		a[i] = totwostring(x[i]);
	}
	string s = "";
	if(k == 0){
		int cnt = 0;
		for(int i = 1;i <= n;i++){
			if(x[i] == 0) cnt++;
			else if(x[i] == x[i + 1]){
				cnt++;
				x[i + 1] = -1e9;
			}
 		}
 		cout<<cnt<<endl;
	}
	else {
		dfs(0,0,"");
		cout<<mx<<endl;
	}
	return 0;
}
