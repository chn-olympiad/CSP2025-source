#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10000010];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	int j=1;
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	j--;
	sort(a+1,a+j+1,cmp);
	for(int i=1;i<=j;i++){
		cout<<a[i];
	}
	return 0;
} 
