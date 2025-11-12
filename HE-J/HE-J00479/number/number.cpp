#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
void oo(int &m,int &n){
	int c=m;
	m=n;
	n=c;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.length();
	int sum=0;
	for(int i=0;i<l;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++sum]=s[i]-'0';
		}
	}
	for(int i=1;i<=sum;i++){
		int maxx=a[i];
		int ans=i;
		for(int j=i+1;j<=sum;j++){
			if(a[j]>maxx){
				maxx=a[j];
				ans=j;
			}
		}
		oo(a[i],a[ans]);
	}
	for(int i=1;i<=sum;i++){
		cout<<a[i];
	}
	return 0;
} 
