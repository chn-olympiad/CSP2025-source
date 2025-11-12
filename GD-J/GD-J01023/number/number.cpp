#include<bits/stdc++.h>
using namespace std;
char c;
int n,a[2415141];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c){
		if(c>='0'&&c<='9') a[++n]=c-'0';
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) cout<<a[i];
	return 0;
} 
