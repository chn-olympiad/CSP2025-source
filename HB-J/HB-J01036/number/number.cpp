#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N];
int k=0;
char c[N];
bool f=0;
bool cmp(int q,int p){
	return q>p;
	}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
		    a[k]=s[i]-48;
		    k++;	
			}
		}
	sort(a+0,a+k+1,cmp);
	if(a[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<k;i++){
	   c[i]=a[i]+48;
	}
	for(int i=0;i<k;i++){
		cout<<c[i];
		}
	return 0;
	} 
