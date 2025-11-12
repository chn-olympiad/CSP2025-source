#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s;
	int l=s.size(),sum=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			sum++;
			a[sum]=int(s[i]-'0');
		}
	}
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		cout<<a[i];
	}
	return 0;
}
