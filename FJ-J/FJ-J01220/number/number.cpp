#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	int f=-1;
	for(int i=0;i<l;i++){
		char c=s[i];
		int b=c-'0';
		
		if(b<10){
			f++;
			a[f]=b;
		}
	}
	sort(a,a+f);
	reverse(a,a+f);
	for(int i=0;i<=f;i++){
		cout<<a[i];
	}
	return 0;
} 
