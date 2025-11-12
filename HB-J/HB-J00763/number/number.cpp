#include <bits/stdc++.h>
using namespace std;
string s;
long long a[100005];
bool cmp(int x,int y){
	return x>y;
}
int zh(char c){
	if(c=='0'){
		return 0;
	}
	else if(c=='1'){
		 return 1;
	 }
	else if(c=='2'){
		return 2;
	} 
	else if(c=='3'){
		 return 3;
	 }
	else if(c=='4'){
		 return 4;
	 }
	else if(c=='5'){
		 return 5;
	 }
	else if(c=='6'){
		 return 6;
	 }
	else if(c=='7'){
		 return 7;
	 }
	else if(c=='8'){
		 return 8;
	 }
	else if(c=='9'){
		 return 9;
	 }
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long len=s.size(),j=1,sum=0;
	for(int i=1;i<=len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[j]=zh(s[i]);
			sum++;
		}
		j++;
	}
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=sum;i++){
		cout<<a[i];
	}
return 0;
}
