#include <bits/stdc++.h>
using namespace std;
string s;
int p[1000005];
int sum;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l = s.size();
	int k = 0;
	for(int i = 0; i < l; i++){
		
		if(s[i] >= '0' && s[i] <= '9'){
			p[k] = s[i] - '0';
			sum++;
			k++;
		}
	}
	sort(p,p + sum,cmp);
	for(int i = 0; i < sum; i++){
		cout<<p[i];
	}
	return 0;
}
