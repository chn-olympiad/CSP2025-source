#include<bits/stdc++.h>
using namespace std;
int m,a[1000001];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<int(s.size());i++){
		if(s[i]=='0'){
			a[m]=0;
			m+=1;
		}else if(s[i]=='1'){
			a[m]=1;
			m+=1;
		}else if(s[i]=='2'){
			a[m]=2;
			m+=1;
		}else if(s[i]=='3'){
			a[m]=3;
			m+=1;
		}else if(s[i]=='4'){
			a[m]=4;
			m+=1;
		}else if(s[i]=='5'){
			a[m]=5;
			m+=1;
		}else if(s[i]=='6'){
			a[m]=6;
			m+=1;
		}else if(s[i]=='7'){
			a[m]=7;
			m+=1;
		}else if(s[i]=='8'){
			a[m]=8;
			m+=1;
		}else if(s[i]=='9'){
			a[m]=9;
			m+=1;
		}
	}
	sort(a,a+m+1);
	for(int i=m;i>0;i--){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
