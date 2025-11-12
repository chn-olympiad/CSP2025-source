#include<bits/stdc++.h>
using namespace std; 
string s;
int t,ans,b[100005];
int cmp(int x,int y){
	return x>=y;
}
int main(){
    freopen("number.in","r",stdin);   
    freopen("number.out","w",stdout);
    cin>>s;
    t=s.size();
    for(int i=0;i<t;i++){
		if(s[i]>='0'&&s[i]<='9')
			cout<<s[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
