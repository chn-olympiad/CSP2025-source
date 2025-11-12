#include<bits/stdc++.h>
using namespace std;
int a[1000001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	int lens=0;
	int k=1;
	cin>>s;
	lens=s.length();
	for(int i=0;i<lens;i++){
		if(s[i]>='0'&&s[i]<='9')
		{
			a[k]=int(s[i]-'0');
			k++;
		}
	}
	int n=k-1;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
}
