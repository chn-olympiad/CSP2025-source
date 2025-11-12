#include<bits/stdc++.h>
using namespace std;
string a;
int b[100005];
int j=0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			j++;
			b[j]=a[i];
		}
	}
	
	sort(b+1,b+1+j,cmp);
	
	for(int i=1;i<=j;i++){
	   cout<<(char)b[i];
	}
	
	return 0;
}
