#include<bits/stdc++.h>
using namespace std;
long long a[100000],c;
string n;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int b=0;
while(cin>>c){
	n+=c;
	if (c>=0&&c<=9){
		a[b]=c;
		b++;
	}
}
for (int i=0;i<b;i++){
	for (int j=1;j<b;j++){
		if (a[i]>a[j]){
			swap(a[i],a[j]);
		}
	}
}
for (int i=0;i<b;i++){
	cout<<a[i];
}
	return 0;}
