#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;

string s;
int x=0,a[N];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[x]=s[i]-'0';
			x++;
		}
	}
	sort(a,a+x);
	for(int i=x-1;i>=0;i--){
		cout<<a[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}