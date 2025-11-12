#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<int> a;
    stack<int> b;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a.push_back(s[i]-'0');
        }
    }int min1,min2;
    for(int i=0;i<a.size();i++){
        min1=10;
        for(int j=0;j<a.size();j++){
        	if(a[j]<min1){
        		min1=a[j];
        		min2=j;
			}
		}
		b.push(min1);
		a[min2]=10;
    }
    while(!b.empty()){
    	cout<<b.top();
    	b.pop();
	}
 return 0;   
}
