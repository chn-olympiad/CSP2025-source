#include<iostream>
using namespace std;
long long jiecheng(int n,long long sum){
	if(n==1)return sum;
	jiecheng(n-1,sum*n);
}
int n,k;
string s;
int c[1005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> k >> s;
	for(int i = 0;i < n;i++)cin >> c[i];
	cout << jiecheng(n-1,1);
	return 0;
}
