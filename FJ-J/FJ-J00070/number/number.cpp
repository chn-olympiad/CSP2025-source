#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int a[1000000+10];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int x=s.size();
	s=" "+s;
	int cnt=0;//¶àÉÙÊı×Ö 
	for(int i=1;i<s.size();i++){
		if(s[i]=='0'){
			a[i]=0;
			cnt++;
		}
		else if(s[i]=='1'){
			a[i]=1;
			cnt++;
		}
		else if(s[i]=='2'){
			a[i]=2;
			cnt++;
		}
		else if(s[i]=='3'){
			a[i]=3;
			cnt++;
		}
		else if(s[i]=='4'){
			a[i]=4;
			cnt++;
		}
		else if(s[i]=='5'){
			a[i]=5;
			cnt++;
		}
		else if(s[i]=='6'){
			a[i]=6;
			cnt++;
		}
		else if(s[i]=='7'){
			a[i]=7;
			cnt++;
		}
		else if(s[i]=='8'){
			a[i]=8;
			cnt++;
		}
		else if(s[i]=='9'){
			a[i]=9;
			cnt++;
		}
	}
	sort(a+1,a+1+x,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
