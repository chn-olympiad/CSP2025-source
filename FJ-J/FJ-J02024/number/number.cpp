#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int b[1000001];
	getline(cin,a);
	int l=a.size();
	int j=0;
//	cout<<a[0]-48<<a[1]-48;
	for(int i=0;i<l;i++){
		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'){
			b[j]=a[i]-48;
			j++;
		}
	}
	sort(b,b+j+1);
	for(int i=j;i>0;i--){
		cout<<b[i];
	}
}
