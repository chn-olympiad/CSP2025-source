#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int k=0,len=s.size();
    for(int i=0;i<len;i++){
        if('0'<=s[i] && s[i]<='9'){
			a[k]=s[i]-'0';
            k++;
        }
    }
    int k1=k;
    while(k--){
	int mx=0,pos=0;
    for(int i=0;i<=k1;i++){
        if(a[i]>=mx){
			mx=a[i];
			pos=i;
		}
	}
    a[pos]=0;
	cout<<mx;
	}
    cout<<endl;
	return 0;
}
