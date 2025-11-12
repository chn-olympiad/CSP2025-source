#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+2;
string s;
int cnt,a[N];
bool cmp(int a,int b){return a>b;}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    std::cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	std::sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++) std::cout<<a[i];
}
