#include<bits/stdc++.h>
#include<set>
using namespace std;
string s;
int a[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=0;
	cin>>s;
	set<string>d;
	d.insert(s);
	for(int i=1;i<=d.size();i++){
		if(s[i]=='1'){
			a[n]=1;
			n++;
		}else	if(s[i]=='2'){
			a[n]=2;
			n++;
		}else if(s[i]=='3'){
			a[n]=3;
			n++;
		}else if(s[i]=='4'){
			a[n]=4;
			n++;
		}else if(s[i]=='5'){
			a[n]=5;
			n++;
		}else if(s[i]=='6'){
			a[n]=6;
			n++;
		}else	if(s[i]=='7'){
			a[n]=7;
			n++;
		}else	if(s[i]=='8'){
			a[n]=8;
			n++;
		}else	if(s[i]=='9'){
			a[n]=9;
			n++;
		}else if(s[i]=='0'){
			a[n]=0;
			n++;
		}
	}
	sort(a+1,a+1+n);
	for(int i=n;i>0;i--){
		cout<<a[i];
	}
	return 0;
} 
