#include<iostream>
using namespace std;
int sum[10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(char c:s)if(c>='0'&&c<='9')sum[c-'0']++;
	for(int i=9;i>=0;i--)while(sum[i]--)cout<<i;
	return 0;
}
