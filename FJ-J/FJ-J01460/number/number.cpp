#include<bits/stdc++.h> 
using namespace std;
string a;
int b[1000010],j=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]-'0'>=0&&a[i]-'0'<=9){
			b[j]=a[i]-'0';
			j++;
		}
	}
	sort(b+1,b+j+1);
	for(int i=j;i>=2;i--){
		cout<<b[i];
	}
	return 0;
}
