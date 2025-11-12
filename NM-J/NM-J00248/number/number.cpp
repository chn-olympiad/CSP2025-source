#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
string s;
int ans[100010];
int a,sum;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            ans[a]=s[i]-'0';
            a++;
        }
    }
    for(int i=0;i<=a;i++){
    	for(int j=i;j<=a;j++){
    		if(ans[j+1]>ans[j]){
    			sum=ans[j];
    			ans[j]=ans[j+1];
    			ans[j+1]=sum;
			}
		}
	}
    for(int i=0;i<a;i++){
    	cout<<ans[i];
    }
    return 0;
}

