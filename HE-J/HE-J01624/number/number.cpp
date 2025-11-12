#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],n;
char c;
bool cmp(int d,int b){
	return d>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c){
		if(c>='0'&&c<='9'){
			n++;
			a[n]=c-'0';
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
} 
