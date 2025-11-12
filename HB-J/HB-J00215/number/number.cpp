//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
using namespace std;
constexpr const int N=1e6;
int n;
char s[N+1+1],a[N+1];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>(s+1);
	for(int i=1;s[i];i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++n]=s[i];
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;1<=i;i--){
		cout<<a[i];
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
