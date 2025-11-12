#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],cnt;
char c;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c){
		if(c>='0'&&c<='9'){
			a[cnt++]=c-'0';
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
}
