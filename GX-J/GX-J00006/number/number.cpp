#include<bits/stdc++.h>

using namespace std;

int f[1000010];
string s;
int n,d,m;

int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
//a=97,0=48,9=57,' '=32

cin>>s;
int p=sizeof(s);
for(int i=0;i<p;i++){
	n=s[i];
	if(n<97){
		f[d]=n-48;
		d++;
	}
	if(n==0) break;
}

for(int i=1;i<=d;i++){
	for(int j=d-1;j>=1;j--){
		if(f[j]>f[j-1]){
			int a=f[j];
			f[j]=f[j-1];
			f[j-1]=a;
		}
	}
}
for(int i=0;i<d-1;i++){
	cout<<f[i];
}


return 0;
}


