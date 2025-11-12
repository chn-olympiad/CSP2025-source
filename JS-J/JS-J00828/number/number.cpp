#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
int m[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string a;
	cin>>a;
	n=a.size();
	for(long long i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			m[cnt]=a[i]-'0';
			cnt++;
		}
	}
	sort(m,m+cnt,cmp);
	for(long long i=0;i<cnt;i++){
		cout<<m[i];
	}
	return 0;
}
