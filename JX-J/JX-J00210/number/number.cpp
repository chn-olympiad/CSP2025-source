#include<bits/stdc++.h>
using namespace std;
string s;
long long k,n,m,a[10005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			a[k]=1;
			k++;
		}else
		if(s[i]=='2'){
			a[k]=2;
			k++;
		}else
		if(s[i]=='3'){
			a[k]=3;
			k++;
		}else
		if(s[i]=='4'){
			a[k]=4;
			k++;
		}else
		if(s[i]=='5'){
			a[k]=5;
			k++;
		}else
		if(s[i]=='6'){
			a[k]=6;
			k++;
		}else
		if(s[i]=='7'){
			a[k]=7;
			k++;
		}else
		if(s[i]=='8'){
			a[k]=8;
			k++;
		}else
		if(s[i]=='9'){
			a[k]=9;
			k++;
		}else
		if(s[i]=='0'){
			a[k]=0;
			k++;
		}
	}
	sort(a,a+k,cmp);
	for(int i=0;i<k;i++){
		cout<<a[i];
	}
	return 0;
}
