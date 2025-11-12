#include<bits/stdc++.h>
using namespace std;
string a[1000001];
int b[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i=1;
	while(cin){
		cin>>a[i];
		i++;
	}
	i--;
	cout<<i;
	int p=1;
	for(int u=1;u<=10;u++){
		if(a[i]=="0")b[p]==0,p++;
		if(a[i]=="1")b[p]==1,p++;
		if(a[i]=="2")b[p]==2,p++;
		if(a[i]=="3")b[p]==3,p++;
		if(a[i]=="4")b[p]==4,p++;
		if(a[i]=="5")b[p]==5,p++;
		if(a[i]=="6")b[p]==6,p++;
		if(a[i]=="7")b[p]==7,p++;
		if(a[i]=="8")b[p]==8,p++;
		if(a[i]=="9")b[p]==9,p++;
	}
	p--;
	sort(b+1,b+p+1);
	for(int j=1;j<=p;j++){
		cout<<b[j];
	}
	return 0;
}


















