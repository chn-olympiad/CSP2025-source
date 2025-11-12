#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int cmp (int a,int b){
	return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

   string s;
   string ss;
    cin>>s;
    int t=s.size();
    for(int i=0;i<t;i++){
        if(s[i]<'a'){
            ss+=s[i];
        }
    }
    t=ss.size();

    for(int i=0;i<t;i++){
    	a[i]=ss[i]-'0';
	}
    sort(a,a+t,cmp);
    for(int i=0;i<t;i++){
    	cout<<a[i];
	}
    return 0;

}
