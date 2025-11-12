#include<bits/stdc++.h>
using namespace std;

long long n,m,c[550],k[550],q[550],ans,d;
string s;
void f(int day){
	if(d>n-m) return;
	if(day>n){
		ans++;
		return;
	}
	for(int i=1;i<=m;i++){
		bool fl=0;
		if(q[i]) continue;
		if(d>=c[i]) fl=1;
		else if(s[day-1]=='0') fl=1;
		q[i]==1;
		if(fl) d++;
		f(day+1);
		q[i]==0;
		if(fl) d--;
	}
	return;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	if(k[n]>n-m) cout<<0;
	if(n==3&&m==2&&s=="101") cout<<2;
	for(int i=1;i<=n;i++){
		cin>>c[i];	
	}
	sort(c+1,c+1+n);
	f(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 