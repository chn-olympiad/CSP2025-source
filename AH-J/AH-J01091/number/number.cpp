#include<bits/stdc++.h>
using namespace std;

string s;
int n,l;
int a[1000005];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	n=s.size();
	l=0;
	
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++l]=s[i]-'0';
		}
	}
	
	sort(a+1,a+l+1,cmp);
	
	for(int i=1;i<=l;i++){
		cout<<a[i];
	}
	
	return 0;
}
