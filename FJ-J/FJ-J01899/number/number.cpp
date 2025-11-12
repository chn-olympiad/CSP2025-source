#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int p=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[p]=(int)s[i]-'0';
		    p++;
		}
	}
	sort(a,a+p,cmp);
	for(int i=0;i<p;i++){
		cout<<a[i];
	}
} 
