#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdin);
    string s;
    cin>>s;
    if(s.size()==1){
        cout<<s;
        return 0;
    }
    if(s.size()==2){
        if(s[1]<='9' && s[1]>='1'){
            if(s[0]<='9' && s[0]>='1'){
                if(s[0]<=s[1]){
                    cout<<s[1]<<s[0];
                    return 0;
                }
                else{
                    cout<<s[0]<<s[1];
                    return 0;
                }
        }
        cout<<s[1];
        return 0;
    }
    if(s[0]<='9' && s[0]>='1' && (s[1]>'9' || s[1]<'1')){
        cout<<s[0];
        return 0;
}
}
int i2;
char max1;
string q;
int o=s.size();
    while(o--){
		for(int i=0;i<s.size();i++){
			if(s[i]<='9' && s[i]>='1' && s[i]>max1){
				max1=s[i];
				i2=i;
	    }
	}
	q=max1;
	max1=0;
	s[i2]=0;
}
	cout<<q;
    return 0;
}
