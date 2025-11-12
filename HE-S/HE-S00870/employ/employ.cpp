#include<bits/stdc++.h>//暴力做得都费劲 
using namespace std;
const int MO = 998244353;
int n,m;
bool s[510];
int c[510];
int a[510];
int ans = 0;
//算出所有情况
//逐个判断 
bool pan(){
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(s[i] && a[i] < i-1 )	cnt++;
	}
	if(cnt==m)	return 1;
	return 0;
}
void suan(int w){	//当前处理位数 
	for(int i = w;i<=n;i++){
		a[w] = c[i];
		if(w == n){
			ans+=pan();
		}else{
			suan(++w);
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		char c;
		scanf("%s",c);
		s[i] = c - '0';
		cin>>a[i];
	}
	suan(1);
	cout<<0%MO;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
