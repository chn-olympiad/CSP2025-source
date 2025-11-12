#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a[1000010]={'z'},b[1000010]={'z'};
    cin>>a;
    for(int i=0;i<=strlen(a);i++){
    	if(a[i]=='9') cout<<a[i]<<endl;
	}
	for(int i=0;i<strlen(a);i++){
    	if(a[i]=='8') cout<<a[i]<<endl;
	}
	for(int i=0;i<strlen(a);i++){
    	if(a[i]=='7') cout<<a[i]<<endl;
	}
	for(int i=0;i<strlen(a);i++){
    	if(a[i]=='6') cout<<a[i]<<endl;
	}
	for(int i=0;i<strlen(a);i++){
    	if(a[i]=='5') cout<<a[i]<<endl;
	}
	for(int i=0;i<strlen(a);i++){
    	if(a[i]=='4') cout<<a[i]<<endl;
	}
	for(int i=0;i<strlen(a);i++){
    	if(a[i]=='3') cout<<a[i]<<endl;
	}
	for(int i=0;i<strlen(a);i++){
    	if(a[i]=='2') cout<<a[i]<<endl;
    }
	for(int i=0;i<strlen(a);i++){
    	if(a[i]=='1') cout<<a[i]<<endl;
	}
	for(int i=0;i<strlen(a);i++){
    	if(a[i]=='0') cout<<a[i]<<endl;
	}
    return 0;
}
