#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],l;
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[++l] = int(s[i])-48;
		}
	}
	sort(a+1,a+l+1,cmp);
	for(int i = 1;i <= l;i++){
		cout << a[i];
	}
	return 0;
} 
