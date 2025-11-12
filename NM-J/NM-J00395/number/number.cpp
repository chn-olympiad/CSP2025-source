#include<bits/stdc++.h>
using namespace std;
string s;int a[1000007];
int main(){
    cin>>s;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int sl=s.size();int b=0;
    for(int i=0;i<sl;i++){
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            a[b++]=s[i]-'0';
        }
    }sort(a,a+b);
    for(int i=b-1;i>=0;i--){
		printf("%d",a[i]);
	}
    cout<<endl;
    return 0;
}
