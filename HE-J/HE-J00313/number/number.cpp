#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005],n,j=1;
bool d;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			d=1;
		}
		else{
			d=0;
			break;
		}
	}
	n=s.size();
	if(d==1){
		for(int i=0;i<n;i++){
			a[i]=(int)s[i]-48;
		}
		sort(a,a+n,greater<int>());
		for(int i=0;i<n;i++){
			cout<<a[i];
		}
		
	}
	else{
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j++]=(int)s[i]-48;
		}
	}
	sort(a+1,a+1+j,greater<int>());
	for(int i=1;i<j;i++){
		cout<<a[i];
	}
    }
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
