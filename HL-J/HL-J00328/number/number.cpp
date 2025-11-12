#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen(number.in,r,stdin);
	freopen(number.out,w,stdout);
	char s[1001]={};
	int b[1001]={};
	cin>>s;
	int x=0;
	int len=strlen(s);
	int n=0;
	int y=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			b[n]=s[i]-('1'-1);
			n++;
		}
	

	}for(int i=0;i<n-1;i++){
    	for(int j=i;j<n-1;j++){
    		if(b[i]>b[i+1] ){
	    		x=b[i+1];   //ц╟ещ 
				b[i+1]=b[i];
				b[i]=x;
			}
    	
		}
	}for(int i=n-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}
