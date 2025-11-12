#include<bits/stdc++.h> 
using namespace std;

const int N = 1e6+5;
long long i,j,n,m,k,l,x,y,a[N];
string s,s1;
char c[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	n = 0;
	for(i = 0;i < s.size();i ++){
		if(isdigit(s[i])){
			c[++ n] = s[i];
		}
	}
	sort(c+1,c+n+1);
	for(i = n;i >= 1;i --){
		s1 += c[i];
	}
	cout <<s1;
	return 0;
}