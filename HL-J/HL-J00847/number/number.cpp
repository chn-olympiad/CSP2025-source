#include <bits/stdc++.h>
using namespace std;
struct node{
	int b;
}a[1000000];
string s;
int coun=1;
bool cmp(node a,node c){
	return a.b>c.b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
	   if(s[i]-'0'<=10&&s[i]-'0'>=-1){  
	   	a[coun].b=s[i]-'0';
	   	coun+=1;
	   		
	   }	
	}
	//cout<<"____"<<endl;
	sort(a+1,a+coun,cmp);
	for(int i=1;i<coun;i++){
	   cout<<a[i].b;	
	}
	
	
	
	return 0;
}
