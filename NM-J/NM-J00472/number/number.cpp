#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",std.out);
    string s;
    cin>>s;
    int j=0,r,l;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[j]=s[i];
            j++;
        }
    }
    if(j==1){
    	cout<<s;
    	return 0;
	}
	for(int i=1;i<=j;i++){
		r=a[i],l=a[i-1];
		if(r>l){
            a[i-1]=a[i];
            a[i]=l;
        }
    }
    for(int i=0;i<j;i++){
        cout<<a[i];
    }
    return 0;
}
