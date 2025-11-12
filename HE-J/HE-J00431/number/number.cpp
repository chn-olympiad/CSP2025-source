#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int sz=a.size();
	char shu[sz];
	for(int i=0,j=0;i<sz;i++){
		if('0'<=a[i]&&a[i]<='9'){
			shu[j]=a[i];
			j++;
		}
	}
	sort(shu,shu+sz,cmp);
	for(int i=0;i<sz;i++)
		if('0'<=shu[i]&&shu[i]<='9')
			cout<<shu[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
