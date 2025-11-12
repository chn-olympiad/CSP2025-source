#include <bits/stdc++.h>
using namespace std;

string s;
int a[1000010];
int n,m=0; 

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	n = s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			m++;
			a[m] = s[i]-'0';
		}
	}
	sort(a+1,a+1+m);
	while(m>1&&a[m]==0)m--;
	for(int i=m;i>0;i--)cout<<a[i];
	
	return 0;
}
