#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],n;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s=s+' ';
	for(int i=1;i<=1000005;i++)
		a[i]=-1;
	for(int i=0;;i++){
		if(s[i]==' '){
			n=i;	
			break;
		}
		if(s[i]<=57)	
			a[i+1]=s[i]-48;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i]==-1)
			return 0;	
		cout<<a[i];	
	}
	return 0;
}
