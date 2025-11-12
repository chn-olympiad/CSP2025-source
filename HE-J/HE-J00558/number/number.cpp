
#include<iostream>
#include<string>
#include<set>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long n=s.size();
	long long x=0;
	long long a[n]={0};
	if(n==1){
		cout<<s;
		return 0;
	}
    else{
    	for(int i=0;i<n;i++){
    		if(s[i]>='1'&&s[i]<='9'){
    			a[x]=s[i]-'0';
    			x++;
			}
		}
	}
   set<long long> w;
    for(int i=0;i<x;i++){
      w.insert(a[i]);
	}
    for(int i=0;i<x;i++){
		cout<<a[i];
	}
	return 0;
}
