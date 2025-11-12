#include<bits/stdc++.h>
using namespace std;
char s;
int a[101],n;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=strlen.(s);
	for(int i=1;i<=l;i++){
		if(i>='0'&&i<='9'){
			a[i]=i;
			n++;
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
} 
