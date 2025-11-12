#include<bits/stdc++.h>
#define N 100010
#define M 6010
#define ll long long
using namespace std;
string s,t;
int a[1000010];
int tot;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++tot]=s[i]-'0'; 
		}
	}
	sort(a+1,a+1+tot,cmp);
	
	for(int i=1;i<=tot;i++){
		t+=a[i]+'0';
	}
	cout<<t;
	return 0;
} 
/*
9:14
切t1
看了大样例发现还用字符串 long long害人不浅说是 
*/
