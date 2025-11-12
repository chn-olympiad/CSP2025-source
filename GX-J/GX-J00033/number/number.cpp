#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=1,k=0,l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]=='0'){
			a[j]=0;
			j++;
			k++;
		}
		else if(s[i]=='1'){
			a[j]=1;
			j++;
			k++;
		}else if(s[i]=='2'){
			a[j]=2;
			j++;
			k++;
		}else if(s[i]=='3'){
			a[j]=3;
			j++;
			k++;
		}else if(s[i]=='4'){
			a[j]=4;
			j++;
			k++;
		}else if(s[i]=='5'){
			a[j]=5;
			j++;
			k++;
		}else if(s[i]=='6'){
			a[j]=6;
			j++;
			k++;
		}else if(s[i]=='7'){
			a[j]=7;
			j++;
			k++;
		}else if(s[i]=='8'){
			a[j]=8;
			j++;
			k++;
		}else if(s[i]=='9'){
			a[j]=9;
			j++;
			k++;
		}
	}
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++)cout<<a[i];
	return 0;
}
