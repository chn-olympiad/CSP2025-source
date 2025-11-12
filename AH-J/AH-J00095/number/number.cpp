#include<bits/stdc++.h>
using namespace std;
long long b,d=1,f;
string a;
long long c[100000];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>a;
for(int i=0;i<int(a.size());i++){
	if(a[i]>='0'&&a[i]<='9'){
		c[d]=a[i]-'0';
		d++;
	}
}
sort(c,c+d);
for(int i=d-1;i>0;i--){
	cout<<c[i];
	}

fclose(stdin);
fclose(stdout);
return 0;
}
