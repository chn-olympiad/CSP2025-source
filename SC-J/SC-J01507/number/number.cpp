#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int p[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a;
	long long y=strlen(a);
	for(int i=0;i<y;i++){
		if(a[i]>=48&&a[i]<=57) p[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(p[i]>0){
			while(p[i]--) cout<<i;
		}
	}
	return 0;
}