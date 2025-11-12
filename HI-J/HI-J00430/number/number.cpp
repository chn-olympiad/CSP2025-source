#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s1;
    int cnt=0;
    string s2;
    cin>>s1;
    for(int i=0;i<s1.size();i++){
    	if(s1[i]>='0'&&s1[i]<='9'){
    		s2=s2+s1[i];
    		
		}
}
    for(int i=0;i<s2.size();i++){
    	a[i]=s2[i];
    	cnt++;
	}
    sort(a+0,a+cnt+1,cmp);
	 for(int i=0;i<cnt;i++){
	 	cout<<(char)a[i];
	 }
	
	
	
	
	
	
	
	return 0;
}
