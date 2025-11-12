#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,b;	
int flag=0;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b+=a[i];
		}
	}
	for(int i=0;i<b.size();i++){
		if(b[i]!='0'){
			flag=1;
			break;
		}
	}
	if(flag){
		for(int i=0;i<b.size();i++){
			if(b[i]=='9'){
				cout<<b[i];
			}
		}
		for(int i=0;i<b.size();i++){
			if(b[i]=='8'){
				cout<<b[i];
			}
		}
		for(int i=0;i<b.size();i++){
			if(b[i]=='7'){
				cout<<b[i];
			}
		}
		for(int i=0;i<b.size();i++){
			if(b[i]=='6'){
				cout<<b[i];
			}
		}
		for(int i=0;i<b.size();i++){
			if(b[i]=='5'){
				cout<<b[i];
			}
		}
		for(int i=0;i<b.size();i++){
			if(b[i]=='4'){
				cout<<b[i];
			}
		}	
		for(int i=0;i<b.size();i++){
			if(b[i]=='3'){
				cout<<b[i];
			}
		}
		for(int i=0;i<b.size();i++){
			if(b[i]=='2'){
				cout<<b[i];
			}
		}
		for(int i=0;i<b.size();i++){
			if(b[i]=='1'){
				cout<<b[i];
			}
		}
		for(int i=0;i<b.size();i++){
			if(b[i]=='0'){
				cout<<b[i];
			}
		}		
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
