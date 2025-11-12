#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
long long a[N];
long long cnt=0;
bool cmp(int o,int p){
	if(o>p)return true;
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	long long n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			a[cnt++]=0;
		}
		else if(s[i]=='1'){
			a[cnt++]=1;
		}
		else if(s[i]=='2'){
			a[cnt++]=2;
		}
		else if(s[i]=='3'){
			a[cnt++]=3;
		}
		else if(s[i]=='4'){
			a[cnt++]=4;
		}
		else if(s[i]=='5'){
			a[cnt++]=5;
		}
		else if(s[i]=='6'){
			a[cnt++]=6;
		}
		else if(s[i]=='7'){
			a[cnt++]=7;
		}
		else if(s[i]=='8'){
			a[cnt++]=8;
		}
		else if(s[i]=='9'){
			a[cnt++]=9;
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
} 
