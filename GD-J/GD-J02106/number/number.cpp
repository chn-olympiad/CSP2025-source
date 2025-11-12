#include<bits/stdc++.h>
using namespace std;
string a;
int b[1100000],wz=1;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(isdigit(a[i])){
			b[wz]=a[i]-48;
			wz++;
		}
	}
	sort(b+1,b+wz);
	for(int i=wz-1;i>=1;i--)cout<<b[i];
	return 0;
}
/*
hua-love×¨Êô
hua-love ´óÀÐorz 
*/
