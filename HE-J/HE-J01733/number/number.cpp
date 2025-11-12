#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	string s;
	cin>>s;
	int i=0,b,c=0;
	while(1){
		if(!s[i]){
			break;
		}
		i++;
	}
	long long a[i];
	for(int j=0;j<i;j++){
		if(!s[j]){
			break;
		}
		if(s[j]=='1'){
			a[c]=1;c++;
		} 
		else if(s[j]=='2'){
			a[c]=2;c++;
		}
		else if(s[j]=='3'){
			a[c]=3;c++;
		}
		else if(s[j]=='4'){
			a[c]=4;c++;
		}
		else if(s[j]=='5'){
			a[c]=5;c++;
		}
		else if(s[j]=='6'){
			a[c]=6;c++;
		}
		else if(s[j]=='7'){
			a[c]=7;c++;
		}
		else if(s[j]=='8'){
			a[c]=8;c++;
		}
		else if(s[j]=='9'){
			a[c]=9;c++;
		}
		else if(s[j]=='0'){
			a[c]=0;c++;
		}
	}
	for(int j=0;j<c-1;j++){
			if(a[j]<a[j+1]){
				b=a[j];
				a[j]=a[j+1];
				a[j+1]=b;
			}
	}
	for(int j=0;j<c;j++){
		cout<<a[j];
	}
	return 0;
}
