#include<bits/stdc++.h>
#include<string>
using namespace std;
string s;
int a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//#Shang4Shan3Ruo6Shui4
	cin>>s;
	int temp=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0'){
			a[temp]=0;
			temp++;
		}else if(s[i]=='1'){
			a[temp]=1;
			temp++;
		}else if(s[i]=='2'){
			a[temp]=2;
			temp++;
		}else if(s[i]=='3'){
			a[temp]=3;
			temp++;
		}else if(s[i]=='4'){
			a[temp]=4;
			temp++;
		}else if(s[i]=='5'){
			a[temp]=5;
			temp++;
		}else if(s[i]=='6'){
			a[temp]=6;
			temp++;
		}else if(s[i]=='7'){
			a[temp]=7;
			temp++;
		}else if(s[i]=='8'){
			a[temp]=8;
			temp++;
		}else if(s[i]=='9'){
			a[temp]=9;
			temp++;
		}
	}
	int l=s.length();
	sort(a,a+l,cmp);
	for(int i=0;i<temp;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
