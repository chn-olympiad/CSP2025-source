#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
	string a;
	int b=0,c=0;
	cin>>a;
	int d=a.size();
	for(int i=0;i<d;i++){
		if(a[i]<a[i+1]){
			c=a[i];
			a[i]=a[i+1];
			a[i+1]=c;
		}
	}
	for(int i=0;i<d;i++){
		for(int j=0;j<d;j++){
			if(a[i]=='9'){
				cout<<a[i];
				break;
			}
		}for(int j=0;j<d;j++){
			if(a[i]=='8'){
				cout<<a[i];
				break;
			}
		}for(int j=0;j<d;j++){
			if(a[i]=='7'){
				cout<<a[i];  
				break;
			}
		}for(int j=0;j<d;j++){
			if(a[i]=='6'){
				cout<<a[i];
				break;
			}
		}for(int j=0;j<d;j++){
			if(a[i]=='5'){
				cout<<a[i];
				break;
			}
		}for(int j=0;j<d;j++){
			if(a[i]=='4'){
				cout<<a[i];
				break;
			}
		}for(int j=0;j<d;j++){
			if(a[i]=='3'){
				cout<<a[i];
				break;
			}
		}for(int j=0;j<d;j++){
			if(a[i]=='2'){
				cout<<a[i];
				break;
			}
		}for(int j=0;j<d;j++){
			if(a[i]=='1'){
				cout<<a[i];
				break;
			}
		}for(int j=0;j<d;j++){
			if(a[i]=='0'){
				cout<<a[i];
				break;
			}
		}
	}
	return 0;
}

