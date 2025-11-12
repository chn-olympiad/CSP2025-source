#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string n;
int k=1;
char a[10000]={' '};
int b[10000],m=0;
int main(){
    freopen("number.in","r",stdin);
    reopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    for(int i=0;i<=6;i++){
    	cin>>a[i];
    	if(a[i]==' ')break;
		else {if(a[i]=='1') {b[k]=1 ;k++;}
        else if(a[i]=='2'){b[k]=2 ;k++;}
		else if(a[i]=='3'){b[k]=3 ;k++;}
		else if(a[i]=='4'){b[k]=4; k++;}
		else if(a[i]=='5'){b[k]=5; k++;}
		else if(a[i]=='6') {b[k]=6; k++;}
        else if(a[i]=='7'){b[k]=7 ;k++;}
	    else if(a[i]=='8') {b[k]=8 ;k++;}
		else if(a[i]=='9') {b[k]=9 ;k++;}
		else if(a[i]=='0') {b[k]=0 ;k++;}
	}
	}
	sort(b,b+k+1);
	//if(b[1]==0)cout<<0;
    if(k==1)cout<<b[1];
	    else for(int i=k;i>1;i--){
	 	    cout<<b[i];
	 }
	 cout<<n;
	return 0;
}

