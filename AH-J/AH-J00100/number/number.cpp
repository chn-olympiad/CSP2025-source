#include<bits/stdc++.h>
using namespace std;
const int N=10e6+5;
char ans[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int l=a.size();
	for(int i=0;i<=l;i++){
		if(a[i]>='0'&&a[i]<='9'){	
			ans[i]=a[i];
		}
	}
	sort(ans,ans+l);
	for(int i=l;i>=0;i--){cout<<ans[i];}
	return 0;
	}
