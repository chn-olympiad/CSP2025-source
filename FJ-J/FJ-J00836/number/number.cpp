#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
char a;
long long i=1,c[1000002];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a){
		if(a>='0'&&a<='9'){
			c[i]=a-'0';
			i++;
		}
	}
	sort(c+1,c+i,cmp);
	for(long long j=1;j<i;j++){
		cout<<c[j];
	}
	return 0;
}
