#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y; 
}
//void fun(int x,int y){
	//cout<<x<<y;
//}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	char b[1000]={0};
	char a[1000]={0};	
	for(int i=0;i<s.size();i++){
		//char a;
		a[i]=s[i];
		if(a[i]=='0'){
			b[i]=a[i];
		}				
		if(a[i]=='1'){
			b[i]=a[i];
		}
		if(a[i]=='2'){
			b[i]=a[i];
		}
		if(a[i]=='3'){
			b[i]=a[i];
		}
		if(a[i]=='4'){
			b[i]=a[i];	
		}
		if(a[i]=='5'){
			b[i]=a[i];
		}
		if(a[i]=='6'){
			b[i]=a[i];
		}
		if(a[i]=='7'){
			b[i]=a[i];
		}
		if(a[i]=='8'){
			b[i]=a[i];
		}
		if(a[i]=='9'){
			b[i]=a[i];
		}                             
		 
	}
	sort(b,b+s.size(),cmp);
	for(int i=0;i<s.size();i++){
		cout<<b[i];
	}
	
	
	return 0;
}
