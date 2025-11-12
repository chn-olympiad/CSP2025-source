#include<bits/stdc++.h>
using namespace std;
string s;
long long v[1000005];
long long cmp(long long x,long long y){
	return x>y;
}
long long num=0;
int main(){
//// 	freopen("number1.in","r",stdin);
//// 	freopen("number1.out","w",stdout);
 	freopen("number.in","r",stdin);
 	freopen("number.out","w",stdout);
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);
 	cin>>s;
 	long long len=s.size();
 	for(int i=0;i<len;i++)
 	{
 		if(s[i]>=48&&s[i]<=58)
 		{
 			num++;
 			v[num]=s[i]-48;
		 }
	 }
 	sort(v+1,v+1+num,cmp);
 	for(int i=1;i<=num;i++)
 	{
 		cout<<v[i];
	 }
 	return 0;
 }
