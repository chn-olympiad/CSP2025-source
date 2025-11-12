#include<bits/stdc++.h>
using namespace std;
string s;
int l,i,j,a[1000009];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	j=1;
	for(i=0;i<l;i++){
		if(s[i]=='0'){
			a[j]=0;
			j++;
		}
		else if(s[i]=='1'){
			a[j]=1;
			j++;
		}
		else if(s[i]=='2'){
			a[j]=2;
			j++;
		}
		else if(s[i]=='3'){
			a[j]=3;
			j++;
		}
		else if(s[i]=='4'){
			a[j]=4;
			j++;
		}
		else if(s[i]=='5'){
			a[j]=5;
			j++;
		}
		else if(s[i]=='6'){
			a[j]=6;
			j++;
		}
		else if(s[i]=='7'){
			a[j]=7;
			j++;
		}
		else if(s[i]=='8'){
			a[j]=8;
			j++;
		}
		else if(s[i]=='9'){
			a[j]=9;
			j++;
		}
	}
	j--;
	sort(a+1,a+j+1);
	for(i=j;i>=1;i--){
		cout<<a[i];
	}
	
	return 0;
} 
