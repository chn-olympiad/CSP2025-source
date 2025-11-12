#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    char s[11105];
    long long d,a=0,n;
    cin>>s;
    n=strlen(s);
	for(int k=0;k<n;k++){
		if(s[k]>'0'&&s[k]<='9'){
			for(int i=0;i<n;i++){
		       for(int j=i+1;j<n;j++){
			       if(s[i]<s[j]){
				      swap(s[i],s[j]);
			        }
	  	        }
		    }
	    }
	}
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a++;
			if(a==1){
			    cout<<s[i]<<'\n';
			    break;
	 	    }
	 	    else if(a==n){
	 	        cout<<s[i];
	 	    }
		    else{
			    if(s[i]>='0'&&s[i]<='9'){
				    cout<<s[i]<<'\n';
		  	    }
		    }
		}
		if(s[i]>='a'&&s[i]<='z'){
			break;
		}
	}
	return 0;
}
