#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long x[100001],a[100001];
long long cmp(int x,int y){
	return x>y;
}	
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
    cout<<s;
	for(int i=1;i<=s.length();i++){
	    if(a[i]=='9'){
			x[i]=a[i];
		}if(a[i]=='8'){
			x[i]=a[i];
		}if(a[i]=='7'){
			x[i]=a[i];
		}if(a[i]=='6'){
			x[i]=a[i];
		}if(a[i]=='5'){
			x[i]=a[i];
		}if(a[i]=='4'){
			x[i]=a[i];
		}if(a[i]=='3'){
			x[i]=a[i];
		}if(a[i]=='2'){
			x[i]=a[i];
		}if(a[i]=='1'){
			x[i]=a[i];
		}if(a[i]=='0'){
			x[i]=a[i];
		}
		cout<<x[i];
	}
	
	return 0;
}