#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s1;
	int a[1000005],k=0;
	memset(a,0,sizeof(a));
	cin>>s1;
	for(int i=0;i<s1.size();i++){
		if((s1[i]-'0')<=9&&(s1[i]-'0')>=0){
			k++;
			a[k]=s1[i]-'0';
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--) cout<<a[i];
	return 0;
}

