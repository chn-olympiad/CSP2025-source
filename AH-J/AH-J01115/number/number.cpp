#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
char s;
int a[1000005],sum,ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s){
		sum++;
		if(int(s)>=48 and int(s)<=57){
			a[ans]=int(s);
			ans++;
		}
	}
	sort(a,a+ans,cmp);
	for(int i=0;i<ans;i++){
		cout<<char(a[i]);
	}
}
