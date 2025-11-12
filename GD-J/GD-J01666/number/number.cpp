#include<bits/stdc++.h>

using namespace std;
string s;
long long a[10000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int w = 1;
	cin >> s;
	int len = s.size();
	for(int i = 0;i < len;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[w] = int(s[i])-int('0');
			w++;
		}
	}
	w--;
	sort(a+1,a+1+w,cmp);
	for(int i = 1;i <= w;i++){
		cout << a[i];
	}
	return 0;
} 
