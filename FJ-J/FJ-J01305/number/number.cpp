#include<bits/stdc++.h>
using namespace std;
string n;
long long p,a[100010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	p=n.size();
	for(int i=0;i<p;i++){
		a[i]=-1;
	}
	for(int i=0;i<p;i++){
		if(n[i]>='0'&&n[i]<='9'){
			a[i]=n[i]-48;
		}
	}
	sort(a+0,a+0+p,cmp);
	for(int i=0;i<p;i++){
		if(a[i]!=-1){
			cout<<a[i];
		}
	}
	return 0;
}
