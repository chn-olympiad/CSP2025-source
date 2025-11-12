#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n=0,ans=0,o=1;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
    	if(s[i]<='9'&&s[i]>='0'){
    		a[n]=s[i]-'0';
    		n++;
		}
	}
	sort(a+0,a+n,cmp);
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}
