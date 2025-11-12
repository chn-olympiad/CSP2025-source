#include<bits/stdc++.h>
using namespace std;
bool o(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int n[a.size()],l=0;
	for(int i=0;i<a.size();i++){
		if(a[i]<='9'&&a[i]>='0'){
			n[l]=a[i]-'0';
			l++;
		}
	}
	sort(n,n+l,o);
	for(int i=0;i<l;i++){
		cout<<n[i];
	}
} 
