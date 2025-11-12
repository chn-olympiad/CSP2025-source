#include<bits/stdc++.h>
using namespace std;
int a[100005],n=0;
char s[100005];
bool  c(int a,int b){
	return  a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string q;
    
    cin>>q;
    for(int i=0;i<q.size();i++){
    	s[i]=q[i];
    		if(s[i]>='0'&&s[i]<='9'){
    		a[n]=s[i]-'0';
    		n++;
    	}
    }
    sort(a,a+n,c);
    for(int i=0;i<n;i++){
    	cout<<a[i];
    }
	return 0;
}
