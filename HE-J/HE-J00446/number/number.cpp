#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int main(){
    cin>>s;
    for(int i=0;i<=0;i++){
    	if(s[i]>='0'&&s[i]<='9'  &&  s[i+1]>='a'&&s[i+1]<='z'){
    		cout<<s[i];
    		break;
		}else if(s[i]>='a'&&s[i]<='z'  &&  s[i+1]>='0'&&s[i+1]<='9'){
    		cout<<s[i+1];
    		break;
		}else if(s[i]>='0'&&s[i]<='9'  &&  s[i+1]>='0'&&s[i+1]<='9'){
			if((s[i]-'0')*10+(s[i+1]-'0')>(s[i+1]-'0')*10+(s[i]-'0')){
				cout<<(s[i]-'0')*10+(s[i+1]-'0');
				break;
			}else{
				cout<<(s[i+1]-'0')*10+(s[i]-'0');
				break;
			}
		}
	}
	for(int i=0;i<=9;i++){
		int max1=s[0],max2;
	    for(int i=0;i<=9;i++){
		    if(s[i]>=max1) max1=s[i];
	    } 
	    max2=max1;
	    cout<<max1-'0';
	}
	return 0;
}
