#include<bits/stdc++.h>
using namespace std;
string s;
int a[100010],n;
int cmp(int c,int b){
	return c>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w"stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			n++;
			if(s[i]=='0'){
				a[i]=0;
				continue;
			}else if(s[i]=='1'){
				a[i]=1;
				continue;
			}else if(s[i]=='2'){
				a[i]=2;
				continue;
			}else if(s[i]=='3'){
				a[i]=3;
				continue;
			}else if(s[i]=='4'){
				a[i]=4;
				continue;
			}else if(s[i]=='5'){
				a[i]=5;
				continue;
			}else if(s[i]=='6'){
				a[i]=6;
				continue;
			}else if(s[i]=='7'){
				a[i]=7;
				continue;
			}else if(s[i]=='8'){
				a[i]=8;
				continue;
			}else if(s[i]=='9'){
				a[i]=9;
				continue;
			}
			cout<<a[i]<<endl;
		}
	}
	sort(a+0,a+0+n,cmp);
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
