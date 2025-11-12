#include<bits/stdc++.h>
using namespace std;
string s;
long long a[100005];
long long n;
long long k=0;
bool cmp(int x,int y){
	if(x>y){
		return true;
	}
	else return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=sizeof(s);i++){
		if(s[i]=='0'){
			a[k]=0;
			k++;
		}
		if(s[i]=='1'){
			a[k]=1;
			k++;
		}
		if(s[i]=='2'){
			a[k]=2;
			k++;
		}
		if(s[i]=='3'){
			a[k]=3;
			k++;
		}
		if(s[i]=='4'){
			a[k]=4;
			k++;
		}
		if(s[i]=='5'){
			a[k]=5;
			k++;
		}
		if(s[i]=='6'){
			a[k]=6;
			k++;
		}
		if(s[i]=='7'){
			a[k]=7;
			k++;
		}
		if(s[i]=='8'){
			a[k]=8;
			k++;
		}
		if(s[i]=='9'){
			a[k]=9;
			k++;
		}
		
	}
	sort(a,a+1+k,cmp);
	for(int i=0;i<k;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
