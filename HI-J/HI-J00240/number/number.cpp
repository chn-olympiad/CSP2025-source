#include<bits/stdc++.h>
#include<cmath>
 bool s(int x,int y){
 	return x>y;
 } 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	long long b[99999]={0},c=0;
	getline(cin,a);
	long long ans=a.size();
	for(int i=0;i<ans;i++){
		if(a[i]=='1'){
			b[c]=1;
			c++;
		}
		else if(a[i]=='0'){
			b[c]=0;
			c++;
		}
		else if(a[i]=='2'){
			b[c]=2;
			c++;
		}
		else if(a[i]=='3'){
			b[c]=3;
			c++;
		}
		else if(a[i]=='4'){
			b[c]=4;
			c++;
		}
		else if(a[i]=='5'){
			b[c]=5;
			c++;
		}
		else if(a[i]=='6'){
			b[c]=6;
			c++;
		}
		else if(a[i]=='7'){
			b[c]=7;
			c++;
		}
		else if(a[i]=='8'){
			b[c]=8;
			c++;
		}
		else if(a[i]=='9'){
			b[c]=9;
			c++;
		}
	}
	sort(b,b+c,s);
	for(int i=0;i<c;i++){
		cout<<b[i];
	}
	return 0;
} 
