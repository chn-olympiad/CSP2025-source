#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number4.in","r",stdin);
	freopen("number4.out","w",stdout);
	string a;
	cin>>a;
	int n=a.size();
	int cnt=0;
	for(int i=1;i<=n;i++){
		if('0'<=a[i-1]&&'9'>=a[i-1]){
			++cnt;
			c[cnt]=a[i-1]-'0';
		}
	}
	sort(c+1,c+1+cnt,cmp);
	for(int i=1;i<=cnt;++i){
		cout<<c[i];
	}
	cout<<endl;
	return 0;
}
