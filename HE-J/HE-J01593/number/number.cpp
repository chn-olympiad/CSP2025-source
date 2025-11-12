#include<bits/stdc++.h>
using namespace std;
char b[1000010];
int cmp(char p,char q){
	if(p>=q){
		return 1;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int l=a.length(),j=0;
	for(int i=0;i<l;i++){
		if('0'<=a[i]&&'9'>=a[i]){
			b[j]=a[i];
			j++;
		}
	} 
	sort(b,b+l,cmp);
	cout<<b;
	return 0;
}
