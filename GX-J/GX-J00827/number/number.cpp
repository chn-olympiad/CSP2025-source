#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int a[N],ans=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<int(s.size());i++)
		if(s[i]>=48&&s[i]<=57) a[ans]=s[i]-'0',ans++;
	sort(a,a+ans,cmp);
	for(int i=0;i<ans;i++){
		printf("%d",a[i]);
	}
	return 0;
}

