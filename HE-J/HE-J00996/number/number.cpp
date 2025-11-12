#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main(){    
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	int j=1;
	cin>>n;
	char a[n.size()+5];
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			a[j++]=n[i];
		}
	}
	
	sort(a+1,a+j,cmp);
	for(int i=1;i<j;i++)printf("%c",a[i]);
	return 0;
} 
