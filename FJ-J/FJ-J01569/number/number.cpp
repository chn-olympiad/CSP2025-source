#include<bits/stdc++.h>
using namespace std;
string a;
const int N=1e6+5;
char num[N];
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int k=0;
	for(int i=0;i<a.size();i++){
		if(!(a[i]>='a'&&a[i]<='z')){
			num[++k]=a[i];
	}
}
	sort(num+1,num+k+1);
	
	for(int i=k;i>=1;i--){
		cout<<num[i];
	}
	return 0;
}
