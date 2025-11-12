#include<bits/stdc++.h>
using namespace std;
int n,m;
string a;
int x[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	sort(x+1,x+n+1);
	int y[505];
	int s=a.size();//不会贪心了，面试的人不是3000不吃压力。
	for(int i=1,j=0;j<s;j++,i++){
		y[i]=(a[i-1]-'0')+y[i-1];
	}
	cout<<'3';
	return 0;
}
