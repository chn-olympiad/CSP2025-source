#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
int n;
cin>>n;
char a[5000];
cin>>a[n];
int b=0;
int c=0;
int d=0;
for(int i=1;i<=n;i++){

	for(int k=1;k<=n;k++){
	char a[i];
	a[i]+=a[i+k];
    if(a[i]>a[n]){
    	b+=a[i]; 
	}

}
if(n>=3||a[i]>2*b){
	d++;
}
cout<<d<<endl;
}
	return 0;
}
