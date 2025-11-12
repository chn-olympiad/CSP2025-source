#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
	int m=0,q,k=0;
    cin>>s;
    int a[s.size()+1];
    for(int i=0;i<s.size();i++){
    	if(s[i]>='0'&&s[i]<='9'){
    		m++;
    		q=s[i]-'0';
    		a[k]=q;
    		k++;
		}
	}sort(a+0,a+m,cmp);
	for(int i=0;i<m;i++){
		cout<<a[i];
	}
	return 0;
} 
