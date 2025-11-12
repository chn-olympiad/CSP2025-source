#include <bits/stdc++.h>
using namespace std;

int a[500000],b[500000],c=0;
bool cmp(int y,int z){
	return y>z;
}	
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);	
	string s;
	cin>>s;	
	int length=s.size();
	for(int i=0;i<length;i++){
		if(a[i]>='0'&&a[i]<='9'){
			//a[i];
			c++;
		}
	}
	sort(a,a+length,cmp);
	for(int i=1;i<=c;i++){
		cout<<a[i];
	}				
	return 0;
}	
