#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
ll b[100005];
string s;
bool comp(int x,int y){
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	ll len=s.size();
	ll num=0,ans=0;
	for(int i=0;i<len;i++){
		if(s[i]=='0'){
			num++;
			a[num]=s[i]-'0';
		}
		if(s[i]=='1'){
			num++;
			a[num]=s[i]-'0';
		}
		if(s[i]=='2'){
			num++;
			a[num]=s[i]-'0';
		}
		if(s[i]=='3'){
			num++;
			a[num]=s[i]-'0';
		}
		if(s[i]=='4'){
			num++;
			a[num]=s[i]-'0';
		}
		if(s[i]=='5'){
			ans++;
			b[ans]=s[i]-'0';
		}
		if(s[i]=='6'){
			ans++;
			b[ans]=s[i]-'0';
		}
		if(s[i]=='7'){
			ans++;
			b[ans]=s[i]-'0';
		}
		if(s[i]=='8'){
			ans++;
			b[ans]=s[i]-'0';
		}
		if(s[i]=='9'){
			ans++;
			b[ans]=s[i]-'0';
		}
	}
	sort(a+1,a+1+num,comp);
	sort(b+1,b+1+ans,comp);
	for(int i=1;i<=ans;i++){
		printf("%d",b[i]);
	}
	for(int i=1;i<=num;i++){
		printf("%d",a[i]);
	}
	return 0;
}
