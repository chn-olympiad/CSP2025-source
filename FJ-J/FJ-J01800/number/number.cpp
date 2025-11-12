#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005],n=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin >> s ;
    for(int i=0;i<s.size();i++){
    	if(s[i]>='0'&&s[i]<='9'){
    		a[n]=s[i]-48;
    		n++;
		}
	}
	sort(a+1,a+n);
	n--;
	if(a[n]!=0){
		for(int i=n;i>=1;i--){
		    cout << a[i] ;
	    }
	}else{
		cout << 0 ;
	}
	
	return 0;
}

