#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
#define sf scanf
#define pf printf
#define str string
str a;
ll len=0,sum[15];
int main(){
	fin("number.in");
	fout("number.out");
	cin>>a;
	len=a.size();
	a=" "+a;
	for(int i=1;i<=len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			sum[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=sum[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
