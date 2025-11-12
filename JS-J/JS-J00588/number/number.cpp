#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string s;
long long int i=0,j=0;
int cnt[1000001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    while( (s[i]<='9' && s[i]>='0')||(s[i]<='z' && s[i]>='a') ){
		if(s[i]<='9' && s[i]>='0'){
			cnt[j]=s[i]-'0';
			j++;
		 }
		i++;
	}
	for(int a=0;a<j;a++){
		for(int b=1;b<j;b++){
			if(cnt[b-1]<cnt[b]) swap(cnt[b-1],cnt[b]);
		}
	}
	for(int a=0;a<j;a++){
		cout<<cnt[a];
	}
}
