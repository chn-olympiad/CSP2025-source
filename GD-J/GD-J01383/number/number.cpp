#include<bits/stdc++.h>
using namespace std;

int a[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int z=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[z]=s[i]-'0';
			z++;
		}
	}
	sort(a,a+z,cmp);
	for(int i=0;i<z;i++){
		printf("%d",a[i]);
	}
	return 0;
} 
