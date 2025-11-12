#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.length();
    char a[1000005];
    int num=0,b[1000005];
    for(int i=0;i<n;i++){
        if(s[i]>='0' && s[i]<='9'){
            a[num]=s[i];
            num++;
        }
    }
    for(int i=0;i<num;i++){
		b[i]=a[i]-48;
	}
	sort(b,b+num);
	for(int i=num-1;i>=0;i--){
		cout<<b[i];
    }
    return 0;
}

