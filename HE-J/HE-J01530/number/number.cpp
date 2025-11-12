#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b=a.size();
	for(int j=0;j<b;j++){
		int maxx=INT_MIN,maxi=-1,p=0;
		for(int i=0;i<b;i++){
			if(int(char(a[i]))>=int('0')&&int(char(a[i]))<=int('9')){
				if(int(char(a[i]))>maxx){
					maxx=int(char(a[i]));maxi=i;p=1;
				}
			}
			
		}
		if(p){
			cout<<a[maxi];
			a[maxi]='a';
		}
		p=0;
	}
	return 0;
} 
