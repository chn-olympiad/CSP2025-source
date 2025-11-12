#include<bits/stdc++.h >
#define ll long long
const int N = 1e5+5;
using namespace std;

int n,m;
int p[N],a[N];
string s;
int k=1,ans=1,len;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1')a[i+1]=a[i]+1;
		else a[i+1]=a[i];
	}
	for(int i=1;i<=n;i++)cin>>p[i];
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++){
		if(p[i]<a[i] or p[i]!=p[i-1]){
			ans*=k;k=1;
		} else {
			k++;
		}
	}
	ans*=k;
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
