#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000005],b[1000005];
	int sumn=0;
	cin>>a;
	long int l=strlen(a);
	for(int i=0;i<l;i++){
		if(a[i]>='0'&&a[i]<='9'){
			sumn++;
			b[sumn]=a[i];
		}
	}
	sort(b+1,b+sumn+1);
	for(int i=sumn;i>0;i--){
		cout<<b[i];
	}
}