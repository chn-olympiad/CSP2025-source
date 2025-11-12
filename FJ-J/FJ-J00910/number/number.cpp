#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],l=0;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[l]=s[i]-'0';
			l++;
		}
	}
	sort(a,a+l);
	while(l--){
		cout <<a[l];
	}
	return 0;
}
