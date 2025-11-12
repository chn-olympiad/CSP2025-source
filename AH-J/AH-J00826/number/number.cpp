#include <bits/stdc++.h>
using namespace std;
char r[10005];
int cnt=0,a=0;
string x;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>x;
for(int i=0;i<=x.size();i++){
	if('1'<=x[i]&&x[i]<='9'){
	r[i]=x[i];
	cout<<r[i];
	cnt=cnt+1;}
}
for(int i=1;i<=cnt;i++){
	for(int j=1;j<=cnt;i++){
	if(r[i]<r[j]){
	a=r[j];
	r[i]=a;
	r[j]=r[i];
	}
}

}
	for(int i=1;i<=cnt+1;i++){
		cout<<r[i];}
return 0;
}
