#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	
	string s;
	int a[100000],index=0;
	cin>>s;
	for(auto j:s){
		if(j>='0'&&j<='9'){
			a[index]=j-'0';
			index++;
		}
	}
	sort(a+0,a+index,cmp);
	for(int i=0;i<index;i++){
		cout<<a[i];
	}
	
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
