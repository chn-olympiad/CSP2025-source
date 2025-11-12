#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[1000005];
bool cmp(int q,int p){
	return q>p;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size(),u=1;
	for(int i=0;i<n;i++){
		if(int(s[i]-'0')>=0&&int(s[i]-'0')<=9){
			a[u]=int(s[i]-'0');
			u++;
		}
	} 
	u--;
	sort(a+1,a+u+1,cmp); 
	string d;
	for(int i=1;i<=u;i++){
		d+=char(a[i]+'0');
	}
	cout<<d;
	return 0;
} 