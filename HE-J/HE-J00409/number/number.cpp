#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
string s;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k = 0;
	for(int i = 0;i<(int)s.size();i++){
		if(isdigit(s[i])){
			a[k++] = s[i] - '0';
		}
	}	
	k--;
	sort(a,a+k,cmp);
	if(a[0]==0){
		cout<<0;
	}else{
		for(int i = 0;i<=k;i++){
			cout<<a[i];
		}
	}
	return 0;
}
