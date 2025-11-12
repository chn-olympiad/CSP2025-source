#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],n=0;
int main () {
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   cin>>s;
   int m=s.size();
   for(int i=0;i<m;i++){
	   if(s[i]>='0'&&s[i]<='9')a[++n]=int(s[i]-'0');
   }
   sort(a+1,a+1+n);
   for(int i=n;i>=1;i--)cout<<a[i];
   return 0;
}
