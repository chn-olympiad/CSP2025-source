#include<bits/stdc++.h>
using namespace std;
int i=0,j=0;
int a[111000],xx,k;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;int ll=s.size();
	for(i=0;i<ll;i++){
		xx=s[i]-'0';
		if(xx>=0&&xx<=9) {
			a[j]=xx;
			j++;
		}
	}
	sort(a,a+j);
	for(i=j-1;i>=0;i--) cout<<a[i];
	return 0;
}
