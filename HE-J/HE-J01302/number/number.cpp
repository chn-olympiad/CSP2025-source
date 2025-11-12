#include<bits/stdc++.h>
using namespace std;
string a,b;
int len,siz;
int num[10000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	len=a.size();
	
	for(int i=0;i<len;i++){
		if(a[i]<'0'||a[i]>'9'){
			a[i]=' ';
		}else if(a[i]!=' ') {
			b[siz]+=a[i];siz++;
		}
	}
	for(int i=0;i<=siz;i++){
		num[i]=b[i]-'0';
	}
	
	sort(num,num+siz);
	for(int i=siz-1;i>=0;i--){
		cout<<num[i];
	}
	return 0;
}
