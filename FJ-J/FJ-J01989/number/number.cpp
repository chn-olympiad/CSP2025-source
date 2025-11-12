#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int l=0;
	cin>>a;
	for(int i=0;a[i];i++){
		if(a[i]>='0'&&a[i]<='9'){
			l++;
			b[l]=a[i]-'0';
		}
	}
	sort(b+1,b+l+1,cmp);
	for(int i=1;i<=l;i++){
		cout<<b[i];
	}
	return 0;
}
