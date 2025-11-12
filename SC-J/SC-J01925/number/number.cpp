#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
long long a[1000000],x=1,i=1;
char s[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);	
	cin>>s;
	for(int i=0;i<=1000004;i++){
		if(s[i]>='0'&&s[i]<='9'){
			x++;
			a[x]=s[i]-'0';
		}
	}
	x--;
	sort(a+1,a+x+1);
	for(int i=x;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}