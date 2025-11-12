#include<bits/stdc++.h>
using namespace std;
string s;
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    int j=0;
	cin>>s;
	if(s.size()==1){
		cout<<s;
	}
    else{
	    for(int i=0;i<=s.size();i++){
		    if((int)s[i]>=48&&(int)s[i]<=57){
			    a[j]=s[i];
			    j++;
		    }
	    }
	    for(int i=0;i<j-1;i++){
		    for(int l=i+1;l<=j-1;l++){
		    	if(a[i]<a[l]){
			    	swap(a[i],a[l]);
			    }
		    }
	    }
	    for(int i=0;i<j;i++){
		    cout<<a[i];
	    }
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
