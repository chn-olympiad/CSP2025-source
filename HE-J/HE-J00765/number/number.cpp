#include<bits/stdc++.h>
using namespace std;
string s;
int n=0,a[1000010];
bool sha(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			a[i]=0;
			n++;
		}else if(s[i]=='1'){
			a[i]=1;
			n++;
		}else if(s[i]=='2'){
			a[i]=2;
			n++;
		}else if(s[i]=='3'){
			a[i]=3;
			n++;
		}else if(s[i]=='4'){
			a[i]=4;
			n++;
		}else if(s[i]=='5'){
			a[i]=5;
			n++;
		}else if(s[i]=='6'){
			a[i]=6;
			n++;
		}else if(s[i]=='7'){
			a[i]=7;
			n++;
		}else if(s[i]=='8'){
			a[i]=8;
			n++;
		}else if(s[i]=='9'){
			a[i]=9;
			n++;
		}
	}
	sort(a,a+n+1,sha);
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
}
