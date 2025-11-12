#include<bits/stdc++.h>
using namespace std;
string n;
long long a[1000005],k=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]=='0'){
			a[k]=(int)n[i]-48;
			k++;
		}else if(n[i]=='1'){
			a[k]=(int)n[i]-48;
			k++;
		}else if(n[i]=='2'){
			a[k]=(int)n[i]-48;
			k++;
		}else if(n[i]=='3'){
			a[k]=(int)n[i]-48;
			k++;
		}else if(n[i]=='4'){
			a[k]=(int)n[i]-48;
			k++;
		}else if(n[i]=='5'){
			a[k]=(int)n[i]-48;
			k++;
		}else if(n[i]=='6'){
			a[k]=(int)n[i]-48;
			k++;
		}else if(n[i]=='7'){
			a[k]=(int)n[i]-48;
			k++;
		}else if(n[i]=='8'){
			a[k]=(int)n[i]-48;
			k++;
		}else if(n[i]=='9'){
			a[k]=(int)n[i]-48;
			k++;
		}
	}
	k--;
	sort(a+1,a+1+k);
	for(int i=k;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
