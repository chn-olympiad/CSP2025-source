#include <bits/stdc++.h>
using namespace std;

int sr,n,m;
int s[120];
int a[20][20];
int i,j,ans = 1;

bool cmp(int s1,int s2){
	if (s1 > s2){
		return true;
	}else{
		return false;
	}
}
int main(){
	cin>>n>>m;
	cin>>sr;
	s[1] = sr;
	for (i = 2;i <= n*m;i++){
		cin>>s[i];
	}
	sort(s+1,s+n*m+1,cmp);
	i = 1;j = 1;
	int c = 1;
	while (s[ans] != sr){
		ans++;
		if (i == n && c == 1){
			j++;
			c = -1;
		}else if (i == 1 && c == -1){
			j++;
			c = 1;
		}else{
			i += c;
		}
	}
	cout<<j<<' '<<i;
	return 0;
}
