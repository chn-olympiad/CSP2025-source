#include<bits/stdc++.h> 
using namespace std;
char a[1000005];
char b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	gets(a);
	int len=strlen(a);
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[i]=a[i];
		}
	}
	if(len==1){
		cout<<a;
	}
	else{
		for(int i=0;i<len;i++){
			for(int j=i+1;j<len;j++){
				if(b[i]<b[j]){
			       swap(b[i],b[j]);
		        }
			}
		    
	    }
	    for(int i=0;i<len;i++){
		    cout<<b[i];
	    }
	}
	
	
	return 0;
}
