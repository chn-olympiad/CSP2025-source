#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5+10;

int n,k,len=0,ans=0;
int a[MAXN],s[MAXN];
bool flag=0;

void solve(){
	if (k==1){
		for (int i=1;i<=n;i++)
			if (a[i]==1) ans++;
		cout <<ans <<'\n';
		return;
	}
	for (int i=1;i<=n;i++){
		if (a[i]==0) ans++;
		else if (i+1<=n&&a[i+1]==1) ans++,i++; 
	}
	cout <<ans <<'\n';
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n >>k;
	for (int i=1;i<=n;i++){
		cin >>a[i];
		if (a[i]>1) flag=1;
	}
	if (!flag){
		solve();
		return 0;
	}
	s[0]=0;
	for (int i=1;i<=n;i++)
		s[i]=s[i-1]^a[i];
	for (int i=1;i<=n;i++){
		for (int j=i-1;j>=len;j--){
			if ((s[i]^s[j])==k){
				len=i,ans++;
				break;
			}
		}
	}
	cout <<ans <<'\n';
	return 0;
}
