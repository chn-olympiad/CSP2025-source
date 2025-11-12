#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],n;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=0;
	for(int i=0;i<s.size();i++){
		int pd=s[i]-'0';
		if(pd<=10&&pd>=0){
			a[len]=pd;
			len++;
			//cout<<pd<<endl;
		}
	}//for(int i=0;i<len;i++) cout<<a[i]<<endl;
	sort(a,a+len,cmp);
	for(int i=0;i<len;i++) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
