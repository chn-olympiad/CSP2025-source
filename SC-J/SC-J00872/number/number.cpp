#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int a[100005];
char c;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c){
		if(c>='0' && c<='9'){
			a[++cnt]=c-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++) printf("%d",a[i]);
	return 0;
} 