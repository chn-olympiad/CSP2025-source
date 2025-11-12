#include<bits/stdc++.h>
using namespace std;
string b;
int a[4000000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	long long cnt=0;
	long long n=b.size();
	for(long long i=0;i<n;i++){
		if(b[i]>='0' && b[i]<='9'){
			a[cnt++]=b[i]-'0';
		}
	}
	sort(a,a+cnt,greater<int>());
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}	
	return 0;
}
