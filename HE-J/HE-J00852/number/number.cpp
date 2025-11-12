#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001],j;
bool b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j-1);
	if(a[j-1]==0){
		b=1;
	}
    if(b==1){
    	j-=1;
    	for(int i=j-1;i>=0;i--){
		    cout<<a[i];
	    }
	    cout<<0;
	}else{
		for(int i=j-1;i>=0;i--){
		    cout<<a[i];
	    }
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
