#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int l[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int count=0;
	for(int i=0;i<a.length();i++){
		if(a[i]<='9' && a[i]>='0'){
			l[++count]=a[i]-'0';
		}
	}
	sort(l+1,l+count+1);
	for(int i=count;i>=1;i--){
		cout<<l[i];
	}
	
	return 0;
}
