#include<iostream>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int b[100];
    int j=0;
    for(int i=0;i<a.size();i++){
    	if(a[i]<='9'&&a[i]>='0'){
    		b[j]=a[i]-'0';
    		j++;
		}
	}
    for(int i=0;i<j;i++){
    	for(int k=i+1;k<j;k++){
    		if(b[i]<b[k]){
    			int q=b[i];
    			b[i]=b[k];
    			b[k]=q;
			}
		}
	}
	if(b[0]!=0){
		for(int i=0;i<j;i++){
    		cout<<b[i];
		}
	}
	else cout<<0;	
    return 0;
}