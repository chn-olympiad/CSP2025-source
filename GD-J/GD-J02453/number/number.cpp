#include<bits/stdc++.h>
using namespace std;
const int N=1e6+33;
char s[N];
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long cnt=0;
	scanf("%s",&s);
	for(int i=0;i<strlen(s);i++){
		int x=s[i]-'0';
		if(x>=0&&x<=9){
			cnt++;
			a[cnt]=x;
		}
	}
	sort(a+1,a+strlen(s)+1,cmp);
	for(int i=1;i<=cnt;i++){
		printf("%d",a[i]);
	}
	return 0;
} 
